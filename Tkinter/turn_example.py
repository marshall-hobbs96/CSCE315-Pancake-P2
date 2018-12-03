from tkinter import *
from player_turn import *
from ai_turn import *
from win_window import *
from random import *
from lose_window import *

game_done = 0
player_stack = "512346789"
ai_stack = "512346789"
window = Tk()
window.geometry("1080x720")
while(game_done != 1):
    player_stack = player_turn(player_stack, ai_stack, window)
    ai_stack = ai_turn(player_stack, ai_stack, str(randint(1,9)) , window)

    if((player_stack == "123456789")):
        game_done = 1
        win_window(window)

    elif((ai_stack == "123456789")):
        game_done = 1
        lose_window(window)
    
