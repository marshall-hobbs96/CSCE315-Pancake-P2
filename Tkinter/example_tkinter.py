from tkinter import *

def draw_pancakes(stack):
    def pancake_pressed(x):
        def wrapper(y = x):
            num = str(y)
            statement = "Pancake " + num + " has been pressed\n"
            print(statement)
            return
        return wrapper
        
    window = Tk()
    pancake_buttons = []
    i = 0
    for x in stack:
        
        num = str(x)
        pancake = Button(window, text=num, command=pancake_pressed(x), pady=10, padx = x*10)
        pancake.grid(column = 360, row = i + 10)
        i = i + 1

 
        
    window.title("Test")
    l = Label(window, text="hello")
    l.grid(column = 0, row = 0)
    window.geometry("1080x720")

    window.mainloop()



draw_pancakes([1, 2, 3, 4, 5, 6, 7, 8, 9])
