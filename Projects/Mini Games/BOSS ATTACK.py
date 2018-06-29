#GAME DIỆT BOSS :3

from random import randint
import os
 
#Vẽ đường gạch ngang (dành cho tạo bảng giao diện)
def printLine():
    print('\n---------------------------------------------------------')
 
#Tạo 2 class người chơi và máy để tương tác nhau
class Player(object):
    pass
 
class Boss(object):
    pass
 
#Định dạng các thông số cho người chơi
class Player(object):
    boss = Boss()
    #Tạo các thông số cho người chơi
    def __init__(self):
        self.HP         = 5000              
        self.ATK        = None
        self.DEF        = None
        self.heal       = None
        self.lifesteal  = None

    #Tạo sức tấn công ngẫu nhiên mỗi lượt cho người chơ0i
    def get_ATK(self):
        self.ATK    = randint(20,35)*100
    
    #Tạo sức phòng thủ ngẫu nhiên cho người chơi
    def get_DEF(self):
        self.DEF    = randint(18,28)*100

    #Tạo ngẫu nhiên số lượng máu hồi nếu dùng bình máu sau mỗi lượt
    def get_heal(self):
        self.heal = randint(15,25)*100

    #Tạo ngẫu nhiên hút máu nếu dùng tấn công sau mỗi lượt
    def get_lifesteal(self):
        self.lifesteal = randint(2,4)

    #In các thông số của người chơi sau mỗi lượt
    def print_info(self):
        print('\nPLAYER Information:')
        print('\nHP = ',self.HP)
        print('\nATK','=',self.ATK)
        print('\nDEF','=',self.DEF)
        printLine()
 
    #Khi người chơi dùng hồi máu
    def use_heal(self):
        ###print('\n...You healed',self.heal,'HP...')
        self.HP = self.HP + self.heal
    
    #Khi người chơi dùng lá chắn
    def use_shield(self):
        ###print('\n...Your DEF got doubled to',self.DEF*2,'DEF')
        self.DEF = self.DEF*2

    #Khi người chơi bị tấn công
    def get_attacked(self):
        ###print('\n...The BOSS attacked you with',boss.ATK,'ATK...')
        if self.DEF < boss.ATK:
            self.HP = self.HP + self.DEF - boss.ATK
 
#Định dạng các thông số cho máy
class Boss(object):
    player = Player()
    #Tạo các thông số cho máy
    def __init__(self):
        self.HP     = 20000
        self.ATK    = None
 
    #Tạo sức tấn công ngẫu nhiên mỗi lượt cho máy
    def get_ATK(self):
        self.ATK    = randint(35,50)*100
 
    #In các thông số hiện có sau mỗi lượt
    def print_info(self):
        print('\nBOSS Information:')
        print('\nHP  =',self.HP)
        print('\nATK =',self.ATK)
        printLine()
 
    #Khi máy bị người chơi tấn công
    def get_attacked(self):
        heal = player.ATK*player.lifesteal//10
        ###print('\n...You attacked the BOSS with',player.ATK,'ATK...')
        ###print('\n...You got',heal,'HP from lifesteal...')
        player.HP   = player.HP + heal 
        self.HP     = self.HP - player.ATK
 
#Thực hiện các lượt chơi
def Move(player,boss):
    #Tạo bảng chọn tấn công hoặc hồi máu cho người chơi
    print('\nChoose your next move:')
    print('\n   1.Heal (%d HP for this turn)' % (player.heal))
    print('\n   2.Shield (double your shield)')
    print('\n   3.Attack (%d HP lifesteal)' % (player.lifesteal*player.ATK//10))
 
    #Yêu cầu người chơi chọn yêu cầu phù hợp
    choose = None    
    while choose not in (1,2,3):
        choose = int(input('\nYour move = '))
    printLine()
 
    #Nếu người chơi chọn hồi máu
    if choose == 1:
        player.use_heal()
    
    #Nếu người chơi chọn tấn công
    elif choose == 2:
        player.use_shield()

    else:
        boss.get_attacked()
    
    #Sau đó người chơi vẫn bị BOSS tấn công
    #Người chơi luôn được ưu tiên tấn công trước
    if boss.HP > 0: player.get_attacked()
    ###printLine()

#Thực hiện xuất các thông số
def Battle(player,boss):
    i = 1

    while True:
        #Lưu lại số máu hiện có của người chơi
        tmp_HP = player.HP
        os.system("cls")
 
        #In số lượt chơi và cắm cờ
        print('TURN',i)
        printLine()
        pWIN = bWIN = False
 
        #Kiểm tra điều kiện thắng mỗi bên
        if boss.HP <= 0:
            boss.HP  = 0
            boss.ATK = 0
            pWIN = True
 
        elif player.HP <= 0:
            player.HP  = 0
            player.ATK = 0
            player.DEF = 0
            bWIN = True
 
        #Lấy ngẫu nhiên các thông số sau mỗi lượt
        player.get_ATK()
        player.get_DEF()
        player.get_heal()
        player.get_lifesteal()
        boss.get_ATK()
        
        #In thông số sau mỗi lượt
        boss.print_info()
        player.print_info()
 
        #Thực hiện nước đi và tăng số lượt nếu game vẫn còn
        if pWIN:
            print('\nPLAYER WIN!')
            input()
            break
 
        if bWIN:
            print('\nBOSS WIN!')
            input()
            break
 
        #Thực hiện nước đi kế tiếp nếu chưa bên nào chết
        Move(player,boss)

        #Thông báo lượng máu thay đổi sau mỗi lượt chơi
        change_HP = player.HP - tmp_HP
        print('\n...Your HP change after this turn: ',end='')
        if change_HP > 0    : print('+',change_HP,'HP...')
        elif change_HP == 0 : print('0 HP...')
        else                : print(change_HP,'HP...')
        printLine()

        #Tăng số đếm lượt chơi nếu trò chơi vẫn còn
        i += 1
        os.system("pause")

#Bằt đầu trò chơi
player = Player()
boss   = Boss()
Battle(player,boss)
