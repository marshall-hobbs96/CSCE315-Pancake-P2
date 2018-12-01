from tkinter import *
import time


def ai_turn(player_stack, ai_stack, ai_move, window):

    for widget in window.winfo_children():
        widget.destroy()
    
    window.grid_columnconfigure(1440, weight = 1)
    window.grid_columnconfigure(720, weight = 1)
    pancake_buttons = []
    ai_buttons = []
    i = 0
    for x in player_stack:
        
        num = str(x)
        pancake = Button(window, text=num, pady=10, padx = x*10, bg = "green")
        pancake.grid(column = 720, row = i + 10)
        pancake_buttons.append(pancake)
        i = i + 1

    for i,x in enumerate(ai_stack[:]):
        
        num = str(x)
        pancake = Button(window, text=num, pady = 10, padx = x*10, bg="green")
        pancake.grid(column = 1440, row = i + 10)
        ai_buttons.append(pancake)
 

    y = ai_move

    temp_stack = ai_stack[0:y:1]
    temp_buttons = ai_buttons[0:y:1]
    temp_stack.reverse()
    temp_buttons.reverse()
    ai_stack[0:y] = temp_stack
    ai_buttons[0:y] = temp_buttons
    for i, x in enumerate(ai_buttons[0:y]):
        ai_buttons[i]["bg"] = "red"

    window.update()
    time.sleep(1)
    window.update()
            
            
    for i, x in enumerate(ai_buttons[0:y]):
        ai_buttons[i].grid_forget()
        ai_buttons[i].grid(column = 1440, row = i + 10)
        ai_buttons[i]["bg"] = "green"


    window.update()
    time.sleep(3)
    window.update()
    
    
    return_stack = ""
    
    for x in ai_stack:
        return_stack = return_stack + str(x)

    print(return_stack)

    for widget in window.winfo_children():
        widget.destroy()
    
    return return_stack


