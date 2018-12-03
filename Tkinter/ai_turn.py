from tkinter import *
import time


def ai_turn(player_stacks, ai_stacks, ai_moves, window):

    player_stack = []
    ai_stack = []
    ai_move = 0

    for x in player_stacks:
        player_stack.append(int(x))

    for x in ai_stacks:
        ai_stack.append(int(x))

    ai_move = int(ai_moves)

    for widget in window.winfo_children():
        widget.destroy()

    turn_label = Label(window, text = "AI Turn", font = ("Comic Sans MS", 30))
    turn_label.place(relx = 0.5, rely=0.75, anchor = CENTER)
    
    window.grid_columnconfigure(1440, weight = 1)
    window.grid_columnconfigure(720, weight = 1)
    pancake_buttons = []
    ai_buttons = []
    i = 0
    for x in player_stack:
        
        num = str(x)
        pancake = Button(window, text=num, pady=10, padx = x*10, bg = "green", font = ("Comic Sans MS", 15))
        pancake.grid(column = 720, row = i + 10)
        pancake_buttons.append(pancake)
        i = i + 1

    for i,x in enumerate(ai_stack[:]):
        
        num = str(x)
        pancake = Button(window, text=num, pady = 10, padx = x*10, bg="green", font = ("Comic Sans MS", 15))
        pancake.grid(column = 1440, row = i + 10)
        ai_buttons.append(pancake)
 

    y = ai_move

    ai_label = Label(window, text = "AI Stack", font = ("Comic Sans MS", 15))
    player_label = Label(window, text = "Player Stack", font = ("Comic Sans MS", 15))
    ai_label.grid(column = 1440, row = 0)
    player_label.grid(column = 720, row = 0)
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
    time.sleep(1)
    window.update()
    
    
    return_stack = ""
    
    for x in ai_stack:
        return_stack = return_stack + str(x)

    print(return_stack)

    for widget in window.winfo_children():
        widget.destroy()
    
    return return_stack




