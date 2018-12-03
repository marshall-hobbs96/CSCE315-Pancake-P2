from tkinter import *
from player_turn import *
from ai_turn import *
from random import *

game_done = 0
player_stack = [5,3,2,6,1,4]
ai_stack = [5,3,2,6,1,4]
window = Tk()
window.geometry("1080x720")
while(game_done != 1):
    player_stack = player_turn(player_stack, ai_stack, window)
    ai_stack = ai_turn(player_stack, ai_stack, randint(1,6) , window)

    if((player_stack == [1,2,3,4,5,6]) | (ai_stack == [1,2,3,4,5,6])):
        game_done = 1
    
