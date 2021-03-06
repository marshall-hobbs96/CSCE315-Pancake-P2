from Tkinter import *
import time


def player_turn(player_stacks, ai_stacks, window):
    sys.argv=["Main"]
    player_stack = []
    ai_stack = []
    player_stacks = player_stacks[::-1]
    ai_stacks = ai_stacks[::-1]

    for x in player_stacks:
        player_stack.append(int(x))

    for x in ai_stacks:
        ai_stack.append(int(x))
    
    for widget in window.winfo_children():
        widget.destroy()
    var = IntVar()

    turn_label = Label(window, text = "Player Turn", font = ("Comic Sans MS", 30))
    turn_label.place(relx = 0.5, rely=0.75, anchor = CENTER)
    
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
    i = 1
    for x in player_stack:
        
        num = str(x)
        pancake = Button(window, text=num, command=pancake_pressed(i - 1,  pancake_buttons), pady=10, padx = x*10, bg = "green", font = ("Comic Sans MS", 15))
        pancake.grid(column = 720, row = i - 1 + 10)
        pancake_buttons.append(pancake)
        i = i + 1

    for i,x in enumerate(ai_stack[:]):
        
        num = str(x)
        pancake = Button(window, text=num, pady = 10, padx = x*10, bg="green", font = ("Comic Sans MS", 15))
        pancake.grid(column = 1440, row = i + 10)
        ai_buttons.append(pancake)

    ai_label = Label(window, text = "AI Stack", font = ("Comic Sans MS", 15))
    player_label = Label(window, text = "Player Stack", font = ("Comic Sans MS", 15))
    ai_label.grid(column = 1440, row = 0)
    player_label.grid(column = 720, row = 0)
    window.wait_variable(var)
    
    return_stack = ""
    
    for x in player_stack:
        return_stack = return_stack + str(x)

    print(return_stack)

    for widget in window.winfo_children():
        widget.destroy()

    return_stack = return_stack[::-1]
    return return_stack

