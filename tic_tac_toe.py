import random

board = [0,1,2,3,4,5,6,7,8]


def display(board):
    print("\t {} | {} | {} ".format(board[0],board[1],board[2]))
    print("\t ___ ____ ____")
    print("\t {} | {} | {} ".format(board[3],board[4],board[5]))
    print("\t ___ ____ ____")
    print("\t {} | {} | {} ".format(board[6],board[7],board[8]))
    print("\t ___ ____ ____")

def Winner(board):
    if(board[0] == board[1] == board[2]):
        if(board[0] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[0]
    if(board[3] == board[4] == board[5]):
        if(board[3] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[3]
    if(board[6] == board[7] == board[8]):
        if(board[6] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[6]
    if(board[0] == board[3] == board[6]):
        if(board[0] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[0]
    if(board[1] == board[4] == board[7]):
        if(board[1] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[1]
    if(board[2] == board[5] == board[8]):
        if(board[2] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[2]
    if(board[0] == board[4] == board[8]):
        if(board[0] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[0]
    if(board[6] == board[4] == board[2]):
        if(board[6] == 'O'):
            print("Computer Wins!")
        else:
            print("Player wins!")
        return board[2]

def try_to_win(board):
    com_p = -1
    if(board[0] == 'O' and board[1] == 'O' and board[2] == 2):
        com_p = 2
    elif((board[0] == 'O' and board[2] == 'O' and board[1] == 1)):
        com_p = 1
    elif((board[1] == 'O' and board[2] == 'O' and board[0] == 0)):
        com_p = 0
    elif((board[3] == 'O' and board[4] == 'O' and board[5] == 5)):
        com_p = 5
    elif((board[3] == 'O' and board[5] == 'O' and board[4] == 4)):
        com_p = 4
    elif((board[4] == 'O' and board[5] == 'O' and board[3] == 3)):
        com_p = 3
    elif((board[6] == 'O' and board[8] == 'O' and board[7] == 7)):
        com_p = 7
    elif((board[6] == 'O' and board[7] == 'O' and board[8] == 8)):
        com_p = 8
    elif((board[7] == 'O' and board[8] == 'O' and board[6] == 6)):
        com_p = 6
    elif((board[0] == 'O' and board[3] == 'O' and board[6] == 6)):
        com_p = 6
    elif((board[0] == 'O' and board[6] == 'O' and board[3] == 3)):
        com_p = 3
    elif((board[3] == 'O' and board[6] == 'O' and board[0] == 0)):
        com_p = 0
    elif((board[1] == 'O' and board[4] == 'O' and board[7] == 7)):
        com_p = 7
    elif((board[1] == 'O' and board[7] == 'O' and board[4] == 4)):
        com_p = 4
    elif((board[4] == 'O' and board[7] == 'O' and board[1] == 1)):
        com_p = 1
    elif((board[2] == 'O' and board[5] == 'O' and board[8] == 8)):
        com_p = 8
    elif((board[2] == 'O' and board[8] == 'O' and board[5] == 5)):
        com_p = 5
    elif((board[5] == 'O' and board[8] == 'O' and board[2] == 2)):
        com_p = 2
    elif((board[0] == 'O' and board[4] == 'O' and board[8] == 8)):
        com_p = 8
    elif((board[0] == 'O' and board[8] == 'O' and board[4] == 4)):
        com_p = 4
    elif((board[4] == 'O' and board[8] == 'O' and board[0] == 0)):
        com_p = 0
    elif((board[2] == 'O' and board[4] == 'O' and board[6] == 6)):
        com_p = 6
    elif((board[2] == 'O' and board[6] == 'O' and board[4] == 4)):
        com_p = 4
    elif((board[4] == 'O' and board[6] == 'O' and board[2] == 2)):
        com_p = 2
    return com_p

comp_check = True
def defence(board):
    com_po = -1
    if(comp_check == True):
        if(board[8] == 'X' and board[0] == 0):
            com_po = 0
        elif(board[0] == 'X' and board[8] == 8):
            com_po = 8
        elif(board[2] == 'X' and board[6] == 6):
            com_po = 6
        elif(board[6] == 'X' and board[2] == 2):
            com_po = 2
    elif((board[0] == 'X' and board[1] =='X' and board[2] == 2)):
        com_po = 2
    elif((board[0] == 'X' and board[2] == 'X' and board[1] == 1)):
        com_po = 1
    elif((board[1] == 'X' and board[2] == 'X' and board[0] == 0)):
        com_po = 0
    elif((board[3] == 'X' and board[4] == 'X' and board[5] == 5)):
        com_po = 5
    elif((board[3] == 'X' and board[5] == 'X' and board[4] == 4)):
        com_po = 4
    elif((board[4] == 'X' and board[5] == 'X' and board[3] == 3)):
        com_po = 3
    elif((board[6] == 'X' and board[8] == 'X' and board[7] == 7)):
        com_po = 7
    elif((board[6] == 'X' and board[7] == 'X' and board[8] == 8)):
        com_po = 8
    elif((board[7] == 'X' and board[8] == 'X' and board[6] == 6)):
        com_po = 6
    elif((board[0] == 'X' and board[3] == 'X' and board[6] == 6)):
        com_po = 6
    elif((board[0] == 'X' and board[6] == 'X' and board[3] == 3)):
        com_po = 3
    elif((board[3] == 'X' and board[6] == 'X' and board[0] == 0)):
        com_po = 0
    elif((board[1] == 'X' and board[4] == 'X' and board[7] == 7)):
        com_po = 7
    elif((board[1] == 'X' and board[7] == 'X' and board[4] == 4)):
        com_po = 4
    elif((board[4] == 'X' and board[7] == 'X' and board[1] == 1)):
        com_po = 1
    elif((board[2] == 'X' and board[5] == 'X' and board[8] == 8)):
        com_po = 8
    elif((board[2] == 'X' and board[8] == 'X' and board[5] == 5)):
        com_po = 5
    elif((board[5] == 'X' and board[8] == 'X' and board[2] == 2)):
        com_po = 2
    elif((board[0] == 'X' and board[4] == 'X' and board[8] == 8)):
        com_po = 8
    elif((board[0] == 'X' and board[8] == 'X' and board[4] == 4)):
        com_po = 4
    elif((board[4] == 'X' and board[8] == 'X' and board[0] == 0)):
        com_po = 0
    elif((board[2] == 'X' and board[4] == 'X' and board[6] == 6)):
        com_po = 6
    elif((board[2] == 'X' and board[6] == 'X' and board[4] == 4)):
        com_po = 4
    elif((board[4] == 'X' and board[6] == 'X' and board[2] == 2)):
        com_po = 2
    com_check = False
    return com_po

def ran_selection(board):
    if(board[4] == 4):
        com_pos = 4
    elif(board[0] == 0):
        com_pos = 0
    elif(board[2] == 2):
        com_pos = 2
    elif(board[6] == 6):
        com_pos = 6
    elif(board[8] == 8):
        com_pos = 8
    elif(board[1] == 1):
        com_pos = 1
    elif(board[3] == 3):
        com_pos = 3
    elif(board[5] == 5):
        com_pos = 5
    elif(board[7] == 7):
        com_pos = 7
    return com_pos

def choose_pos_com(board):
    com_posi = try_to_win(board)
    com_pos = defence(board)
    if(com_posi != -1):
        com_pos = com_posi
    elif(com_pos != -1):
        com_pos = com_pos
    else:
        com_pos = ran_selection(board)
        
    print("The position taken by computer is (out of loop): ",com_pos)
    while(board[com_pos] != com_pos):
        print("The position is already Taken:")
        com_pos = ran_selection(board)
        print("The position taken by computer is (in loop): ",com_pos)
    board[com_pos] = 'O'

def choose_pos(board):
    flag = 1
    cnt = 0
    while(cnt != 9):
        while(flag == 1):
            player_pos = int(input("Enter the position: "))
            if(board[player_pos] != player_pos):
                player_pos = int(input("Enter the another position last one is already taken:"))
            board[player_pos] = "X"
            flag = 0
            cnt = cnt + 1
            display(board)
            if(Winner(board) == 'X'):
                    return
            elif(Winner(board) == 'O'):
                    return
        if(cnt != 9):
            while(flag == 0):
                choose_pos_com(board)
                flag = 1
                global comp_check
                comp_check = False
                cnt = cnt + 1
                display(board)
                if(Winner(board) == 'X'):
                    return
                elif(Winner(board) == 'O'):
                    return
    print("_________GAME TIE_________")

display(board)
choose_pos(board)
display(board)