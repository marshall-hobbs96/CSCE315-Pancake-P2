from Tkinter import *
from player_turn import *
from ai_turn import *
from win_window import *
from random import *
from lose_window import *
from scores import *
import sys


def main():
    print('test')
    arg = sys.argv[1]
    stack = str(arg)
    player_stack = stack
    ai_stack = stack
    in_order_stack = "123456789"
    stack_size = len(stack);
    window = Tk()
    window.geometry("1280x720")
    print(in_order_stack[0:stack_size])
    result = 2 #0 = loss, 1 = win, 2 = tie
    game_done = 0
    while(game_done != 1):
        player_stack = player_turn(player_stack, ai_stack, window)
        ai_stack = ai_turn(player_stack, ai_stack, str(randint(1,9)), window)


        if player_stack[::-1] == in_order_stack[0:stack_size] and ai_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            tie_window(window)
            result = 2
        elif player_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            win_window(window)
            result = 1
        elif ai_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            lose_window(window)
            result = 0

    score = calcScore(result, 4, 4)
    scrs = readScore()
    ins = initials(window, 0)
    score_string = updateScore(scrs, ins,score)
    scores(window,score_string)
            
if __name__ == "__main__":
    main()

