"""Chào mừng bạn đến với game 'Đoán tàu' 
Luật chơi: Trên bản đồ 5x5, bạn có 4 lượt dự đoán xem vị trí
của con tàu đang ẩn giấu nằm ở đâu. Nếu quá số lượt dự đoán
mà vẫn chưa tìm ra con tàu bí ẩn thì bạn thua!"""

from random import randint
import os

#Tạo bản đồ gồm các dấu O
board=[]
for row in range (5):
    board.append(['O']*5)

#In ra bản đồ
def print_board(board):
    os.system('cls')
    print('        1   2   3   4   5\n')
    i=1
    for row in board:
        print(' ',i,'   ','   '.join(row),'\n')
        i+=1
    print('\n--------------------------------------------------\n')

#In bản đồ mở đầu
print_board(board)

#Tạo vị trí ngẫu nhiên của thuyền bí ẩn
ship_col=randint(1,5)
ship_row=randint(1,5)

#Cho 4 lượt dự đoán cho người chơi
for turn in range (4):
    print_board(board)
    print('  Luot thu', turn+1)
    guess_row=int(input('\n  Du doan hang: '))
    guess_col=int(input('\n  Du doan cot: '))

    #Kiểm tra dự đoán đúng với vị trí của thuyền bí ẩn
    if(guess_row==ship_row and guess_col==ship_col):
        board[guess_row-1][guess_col-1]='W'
        print_board(board)
        print('  Chuc mung! Ban da du doan chinh xac\n')
        break
    else:
        board[guess_row-1][guess_col-1]='X'
        #Kiểm tra xem còn lượt chơi hay không
        if(turn==3):
            board[ship_row-1][ship_col-1]='W'
            print_board(board)
            print('  GAME OVER! ',end='')
            print('Vi tri cua thuyen bi an: (%d,%d)' % (ship_row,ship_col))
            break
input()