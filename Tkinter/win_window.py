from Tkinter import *
from time import *


def win_window(window):

    for widget in window.winfo_children():
        widget.destroy()

    win_label = Label(window, text = "YOU WIN!!!!", font = ("Comic Sans MS", 50), fg = "red")
    win_label.place(relx= 0.5, rely = 0.5, anchor = CENTER)
    for x in range(15):
        window.configure(background = "green")
        win_label.configure(fg="red", bg = "green")
        window.update()
        sleep(0.2)
        window.update()
        window.configure(background = "red")
        win_label.configure(fg = "green", bg = "red")
        window.update()
        sleep(0.2)
        window.update()

    window.configure(background = "lightgrey")
    for widget in window.winfo_children():
        widget.destroy()
