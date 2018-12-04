from Tkinter import *
from player_turn import *
from ai_turn import *
from win_window import *
from random import *
from lose_window import *
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
    window.geometry("1080x720")

    game_done = 0
    while(game_done != 1):
        player_stack = player_turn(player_stack, ai_stack, window)
        ai_stack = ai_turn(player_stack, ai_stack, str(randint(1,9)) , window)


        if player_stack == in_order_stack[0:stack_size] and ai_stack == in_order_stack[0:stack_size]:
            game_done = 1
            #tie_window(window)
        elif player_stack == in_order_stack[0:stack_size]:
            game_done = 1
            win_window(window)
        elif ai_stack == in_order_stack[0:stack_size]:
            game_done = 1
            lose_window(window)
            
    
