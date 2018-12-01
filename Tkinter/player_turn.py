from tkinter import *
import time


def player_turn(player_stack, ai_stack, window):

    for widget in window.winfo_children():
        widget.destroy()
    var = IntVar()
    
    def pancake_pressed(x, buttons):
        def wrapper(y = x):
            num = str(y)
            y = y + 1

            statement = "Pancake " + num + " has been pressed\n"
            temp_stack = player_stack[0:y:1]
            temp_buttons = buttons[0:y:1]
            temp_stack.reverse()
            temp_buttons.reverse()
            player_stack[0:y] = temp_stack
            buttons[0:y] = temp_buttons
            for i, x in enumerate(buttons[0:y]):
                buttons[i]["bg"] = "red"

            window.update()
            time.sleep(1)
            window.update()
            
            
            for i, x in enumerate(buttons[0:y]):
                buttons[i].grid_forget()
                buttons[i].grid(column = 720, row = i + 10)
                buttons[i]["bg"] = "green"
                buttons[i]["command"] = pancake_pressed(i, pancake_buttons)

            window.update()
            time.sleep(1)
            window.update()
            var.set(1)
            return
        return wrapper

    window.grid_columnconfigure(1440, weight = 1)
    window.grid_columnconfigure(720, weight = 1)
        
    pancake_buttons = []
    ai_buttons = []
    i = 0
    for x in player_stack:
        
        num = str(x)
        pancake = Button(window, text=num, command=pancake_pressed(x - 1,  pancake_buttons), pady=10, padx = x*10, bg = "green")
        pancake.grid(column = 720, row = i + 10)
        pancake_buttons.append(pancake)
        i = i + 1

    for i,x in enumerate(ai_stack[:]):
        
        num = str(x)
        pancake = Button(window, text=num, pady = 10, padx = x*10, bg="green")
        pancake.grid(column = 1440, row = i + 10)
        ai_buttons.append(pancake)

    window.wait_variable(var)
    
    return_stack = ""
    
    for x in player_stack:
        return_stack = return_stack + str(x)

    print(return_stack)

    for widget in window.winfo_children():
        widget.destroy()

    
    return return_stack

