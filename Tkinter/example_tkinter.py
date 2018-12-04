from tkinter import *



def draw_pancakes(stack):
    test = -1
    def pancake_pressed(x, buttons):
        def wrapper(y = x):
            num = str(y)
            y = y + 1

            test = y

            statement = "Pancake " + num + " has been pressed\n"
            temp_stack = stack[0:y:1]
            temp_buttons = buttons[0:y:1]
            temp_stack.reverse()
            temp_buttons.reverse()
            stack[0:y] = temp_stack
            buttons[0:y] = temp_buttons
            for i, x in enumerate(buttons[0:y]):
                buttons[i].grid_forget()
                buttons[i].grid(column = 360, row = i + 10)
                buttons[i]["command"] = pancake_pressed(i, pancake_buttons)
                #buttons[i]["bg"] = "activebackground"
            print(stack[::1])
            print(statement)
            return
        return wrapper
        
    window = Tk()
    pancake_buttons = []
    i = 0
    for x in stack:
        
        num = str(x)
        if i > test:
            pancake = Button(window, text=num, command=pancake_pressed(x - 1,  pancake_buttons), pady=10, padx = x*10,bg = 'red')
        else:
            pancake = Button(window, text=num, command=pancake_pressed(x - 1,  pancake_buttons), pady=10, padx = x*10,bg='green')
        pancake.grid(column = 360, row = i + 10)
        pancake_buttons.append(pancake)
        i = i + 1

 
        
    window.title("Test")
    l = Label(window, text="hello")
    l.grid(column = 0, row = 0)
    window.geometry("1080x720")

    window.mainloop()



draw_pancakes([1, 2, 3, 4, 5, 6, 7, 8, 9])
