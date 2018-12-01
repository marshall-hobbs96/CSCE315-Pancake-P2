from Tkinter import *
from PIL import ImageTk, Image
numOfPancakes = -1

def setP(p):
	return p
	#numOfPancakes = p
	
	
def drawDifficultyWindow(master):
	sys.argv = ["Main"]
	#master = Tk()
	w = Canvas(master, width=1280, height=720)
	w.pack()

	w.create_text(520,50,text="Set Your Difficulty!",font=("Arial",30), anchor = NW)
	w.create_text(500,125,text="Select Number of Pancakes:",font=("Arial",20), anchor = NW)
	drawPancakeButtons(w)
	
	pancakeScale = Scale(w, from_ = 2, to = 9, tickinterval = 1, length = 1000, orient=HORIZONTAL, sliderlength = 30, font=("Arial",25), command=setP)
	
	w.mainloop()

def instructions(window):
	wind_width = 1280
	wind_height = 720
	c = Canvas(window, width = wind_width, height = wind_height)
	c.pack(expand = YES, fill = BOTH)
	button = Button(window,text = "CONTINUE", command=window.quit)
	button.configure(width = 20, height = 5)
	c.create_window(640,600, window = button)
	window.mainloop()
	c.pack_forget()
	return window
	
def splash():
	sys.argv = ["Main"]
	window = Tk()
	window.title("PANCAKES!!!!!!!!!!!!")
	wind_width = 1280
	wind_height = 720
	c = Canvas(window, width = wind_width, height = wind_height)
	c.pack(expand = YES, fill = BOTH)
	button = Button(window,text = "START", command=window.quit)
	button.configure(width = 20, height = 5)
	c.create_window(1000,600, window = button)
	pic = ImageTk.PhotoImage(Image.open("Pancake.jpg"))
	c.create_image(0,0, image = pic, anchor= NW);
	window.mainloop()	
	c.pack_forget()
	instructions(window);
	
