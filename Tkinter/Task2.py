"""
Leuel Asnake
"""

from Tkinter import *

numOfPancakes = -1

def setP(p):
	return p
	#numOfPancakes = p

def drawPancakeButtons(w):
	pb2 = Button(w, text="2", command=lambda:setP(2), height=2, width=5)
	pb2.place(x=250,y=200)
	pb3 = Button(w, text="3", command=lambda:setP(3), height=2, width=5)
	pb3.place(x=350,y=200)
	pb4 = Button(w, text="4", command=lambda:setP(4), height=2, width=5)
	pb4.place(x=450,y=200)
	pb5 = Button(w, text="5", command=lambda:setP(5), height=2, width=5)
	pb5.place(x=550,y=200)
	pb6 = Button(w, text="6", command=lambda:setP(6), height=2, width=5)
	pb6.place(x=650,y=200)
	pb7 = Button(w, text="7", command=lambda:setP(7), height=2, width=5)
	pb7.place(x=750,y=200)
	pb8 = Button(w, text="8", command=lambda:setP(8), height=2, width=5)
	pb8.place(x=850,y=200)
	pb9 = Button(w, text="9", command=lambda:setP(9), height=2, width=5)
	pb9.place(x=950,y=200)
	
	
def drawDifficultyWindow():
	master = Tk()
	w = Canvas(master, width=1280, height=720)
	w.pack()

	w.create_text(520,50,text="Set Your Difficulty!",font=("Arial",30), anchor = NW)
	w.create_text(500,125,text="Select Number of Pancakes:",font=("Arial",20), anchor = NW)
	#drawPancakeButtons(w)
	
	pancakeScale = Scale(w, from_ = 2, to = 9, tickinterval = 1, length = 1000, orient=HORIZONTAL, sliderlength = 30, font=("Arial",25), command=setP)
	print ( pancakeScale.place(x=150,y=200) )


	
	
	w.mainloop()

if __name__ == "__main__":
		drawDifficultyWindow()
	