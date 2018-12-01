"""
Leuel Asnake
"""

from Tkinter import *
	
def choosePancakes (w):
	w.create_text(500,160,text="Select Number of Pancakes:",font=("Arial",20), anchor = NW)
	
	pancakeScale = Scale(w, from_ = 2, to = 9, tickinterval = 1, length = 1000, orient=HORIZONTAL, sliderlength = 30, font=("Arial",25))
	pancakeScale.place(x=150,y=200)
	
	nextB = Button(w, text="Next", command=lambda:chooseDifficulty(w, pancakeScale.get()), height=3, width=10)
	nextB.place(x=600,y=350)	
	
def chooseDifficulty(w, n):
	w.create_text(500,460,text="Select Difficulty:",font=("Arial",20), anchor = NW)
	diffScale = Scale(w, from_ = 1, to = n, tickinterval = 1, length = 1000, orient=HORIZONTAL, sliderlength = 30, font=("Arial",25))
	diffScale.place(x=150,y=500)
	
def drawDifficultyWindow():
	master = Tk()
	w = Canvas(master, width=1280, height=720)
	w.pack()

	w.create_text(520,50,text="Set Your Difficulty!",font=("Arial",30), anchor = NW)
	
	choosePancakes(w)
	
	submitB = Button(w, text="Submit", height=3, width=10)
	submitB.place(x=600,y=650)
	
	w.mainloop()

if __name__ == "__main__":
		drawDifficultyWindow()
	