"""Chào mừng bạn đến với game CARO 5x5"""
import os

#Tạo bảng để in ban đầu
board=[]
for row in range (5):
    board.append(['*']*5)

#Hàm in bảng sau mỗi lượt chơi
def print_board(board):
    os.system('cls')
    print('      1   2   3   4   5')
    print()
    i=1
    for row in board:
        print(' ',i,' ','   '.join(row),'\n')
        i+=1
    print('------------------------------------------\n')

#Kiểm tra điều kiện thắng 1 (Các hàng trùng nhau)
def isWin1(board):
    #Tạo mẫu hàng thắng
    win_row1=['O']*5
    win_row2=['X']*5

    #Nếu một trong các hàng trong cột trùng với mẫu hàng thắng
    for row in board:
        if(row==win_row1 or row==win_row2):
            print_board(board)
            print(' O WIN!' if (row==win_row1) else ' X WIN!')
            return True

    return False

#Kiểm tra điều kiện thắng 2 (Các cột trùng nhau)
def isWin2(board):
    #Đếm số lượng X và O trên từng cột
    for row in range (5):
        countX=countO=0
        for col in range (5):
            if(board[col][row]=='X'): countX+=1
            elif (board[col][row]=='O'): countO+=1
        
        #Nếu đủ số lượng X hoặc O thì xuất thông báo thắng
        if(countX==5 or countO==5):
            print_board(board)
            print(' O WIN!' if (countO==5) else ' X WIN!')
            return True

    return False

#Kiểm tra điều kiện thắng 5 (Hàng chéo trùng nhau)
def isWin5(board):

    #Đếm số lượng X và O trên từng đường chéo
    countX1=countO1=0                                       #Đếm trên hàng chéo chính
    countX2=countO2=0                                       #Đếm trên hàng chéo phụ
    for row in range (5):
        if(board[row][row]=='X'): countX1+=1
        if(board[row][row]=='O'): countO1+=1
        if(board[row][4-row]=='X'): countX2+=1
        if(board[row][4-row]=='O'): countO2+=1

    #Nếu đủ số lượng X hoặc O thì xuất thông báo thắng
    if(5 in (countX1,countX2,countO1,countO2)):
        print_board(board)
        print(' O WIN!' if (countO1==5 or countO2==5) else ' X WIN!')
        return True

    return False

#Kiểm tra một trong 3 điều kiện thắng (thoã 1 là được)
def isWin(board):
    if(isWin1(board)==True or isWin2(board)==True or isWin5(board)==True):
        return True
    return False

#Lần lượt cho mỗi nước đi (tối đa là 25)
for turn in range (25):
    #Hiện lại bảng sau mỗi nước đi
    print_board(board)
  
    #Quân X đi trước (các nước chẵn 0,2,4,6,8)
    print(' Luot di cua','X' if (turn % 2 == 0) else 'O')
    pick_row = int(input(' Nhap hang: '))
    pick_col = int(input(' Nhap cot: '))

    #Kiểm tra tính hợp lệ của hàng và cột (không nằm ngoài bản đồ và không trùng)
    while(pick_row-1 not in range (0,5) or pick_col-1 not in range (0,5) \
          or board[pick_row-1][pick_col-1] in ('X','O')):
        print('------------------------------------------')
        print(' Hang va cot nhap vao khong hop le!')
        pick_row = int(input(' Nhap lai hang: '))
        pick_col = int(input(' Nhap lai cot: '))
    
    #Đánh dấu nước đi đã chọn
    board[pick_row-1][pick_col-1]=('X' if (turn % 2 == 0) else 'O')

    #Kiểm tra điều kiện thắng
    if(isWin(board)==True):
        break
    elif(turn==24):
        print_board(board)
        print(' TIE')
        break
input()