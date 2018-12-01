from Tkinter import *

def initials(status):	#status is a string with a message about the winner
	window = Tk()
	window.geometry('1280x720')
	window.title("Initials")
	
	#fillers are used to fix spacing in the grid
	fill = Label(window, text = "         ", font=("Arial Bold", 120))
	fill.grid(column=0,row=0)
	
	lbl = Label(window, text=status, font=("Arial Bold", 40))
	lbl.grid(column=1, row=1)
	
	lbl2 = Label(window, text="Please Enter Your Initials Below", font=("Arial Bold", 35))
	lbl2.grid(column=1, row=2)
	
	fill2 = Label(window, text = "            ", font=("Arial Bold", 60))
	fill2.grid(column=0,row=3)

	txt = Entry(window,width=20)
	txt.grid(column=1, row=4)
	
	def clicked():
		initials = txt.get()
		window.destroy()

	fill3 = Label(window, text = "            ", font=("Arial Bold", 25))
	fill3.grid(column=0,row=5)	
		
	btn = Button(window, text="Enter", command=clicked)
	btn.grid(column=1, row=6)
	btn.config(height=2,width=20)

	window.mainloop()
	
	return initials

def scores(scores):		#scores is a string holding the initials and high scores
	window = Tk()
	window.geometry('1280x720')
	window.title("Scores")
	cont = 0
		
	fill = Label(window, text = "                ", font=("Arial Bold", 100))
	fill.grid(column=0,row=0)
	
	lbl = Label(window, text="High Scores", font=("Arial Bold", 40))
	lbl.grid(column=1, row=1)
	
	#print the high scores
	row = 2
	for x in scores:
		score = Label(window, text=x, font=("Arial Bold", 35))
		score.grid(column=1, row=row)
		row = row + 1
		
	fill2 = Label(window, text = " ", font=("Arial Bold", 30))
	fill2.grid(column=0,row=7)
		
	def replay():
		cont = 1
		window.destroy()

	replay = Button(window, text="Play Again", command=replay)
	replay.grid(column=1, row=8)
	replay.config(height=2,width=20)
	
	fill2 = Label(window, text = " ", font=("Arial Bold", 25))
	fill2.grid(column=0,row=9)
	
	def end():
		window.destroy()

	end = Button(window, text="End Game", command=end)
	end.grid(column=1, row=10)
	end.config(height=2,width=20)	
		
	window.mainloop()
	
	return cont # continue - if player wants to play again
	
initials("Sorry, the AI won!")
scores(["AA 0", "BB 0", "CC 0", "DD 0", "EE 0"])