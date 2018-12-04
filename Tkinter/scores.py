from Tkinter import *

def initials(window, status):	#status is a string with a message about the winner
	initials = ""
	#give comment depending on winner
	if status == 0:
		comment = "Sorry, the AI won!"
	elif status == 1:
		comment = "Congratulations, you won!"
	else:
		comment = "It was a tie!"

	#fillers are used to fix spacing in the grid
	fill = Label(window, text = "         ", font=("Arial Bold", 120))
	fill.pack()

	lbl = Label(window, text=comment, font=("Arial Bold", 40))
	lbl.pack()

	lbl2 = Label(window, text="Please Enter Your Initials Below", font=("Arial Bold", 35))
	lbl2.pack()
	
	fill2 = Label(window, text = "            ", font=("Arial Bold", 60))
	fill2.pack()

	txt = Entry(window,width=20)
	txt.pack()

	def clicked():
		initials = txt.get()
		fill.destroy()
		lbl.destroy()
		lbl2.destroy()
		fill2.destroy()
		fill3.destroy()
		btn.destroy()
		txt.destroy()
		window.quit()
		
	fill3 = Label(window, text = "            ", font=("Arial Bold", 25))
	fill3.pack()	
		
	btn = Button(window, text="Enter", command=clicked)
	btn.pack()
	btn.config(height=2,width=20)

	window.mainloop()

	return initials

def scores(window, scoreString):		#scores is a string holding the initials and high scores
	cont = 0
		
	fill = Label(window, text = "                ", font=("Arial Bold", 60))
	fill.pack()
	
	lbl = Label(window, text="High Scores", font=("Arial Bold", 40))
	lbl.pack()
	
	spaces = 0
	scoreCount = 0
	score = ""
	scores = []
	for x in scoreString:
		if x == " ":
			if spaces == 0:
				score = score + x
				spaces = 1
			else:
				scores.append(score)
				score = ""
				spaces = 0
		else: 
			score = score + x
	scores.append(score)

	#print the high scores
	score1 = Label(window, text=scores[0], font=("Arial Bold", 35))
	score1.pack()
	score2 = Label(window, text=scores[1], font=("Arial Bold", 35))
	score2.pack()
	score3 = Label(window, text=scores[2], font=("Arial Bold", 35))
	score3.pack()
	score4 = Label(window, text=scores[3], font=("Arial Bold", 35))
	score4.pack()
	score5 = Label(window, text=scores[4], font=("Arial Bold", 35))
	score5.pack()
		
	#fill2 = Label(window, text = " ", font=("Arial Bold", 30))
	#fill2.grid(column=0,row=7)
		
	def replay():
		cont = 1
		fill.destroy()
		lbl.destroy()
		replay.destroy()
		fill2.destroy()
		end.destroy()
		score1.destroy()
		score2.destroy()
		score3.destroy()
		score4.destroy()
		score5.destroy()

		window.quit()

	replay = Button(window, text="Play Again", command=replay)
	replay.pack()
	replay.config(height=2,width=20)
	
	fill2 = Label(window, text = " ", font=("Arial Bold", 25))
	fill2.pack()
	
	def end():
		window.destroy()

	end = Button(window, text="End Game", command=end)
	end.pack()
	end.config(height=2,width=20)	
		
	window.mainloop()
	
	return cont # continue - if player wants to play again
	
def calcScore(winner, n, d):
	score = 0
	if winner == 1:
		score = n
	elif winner == 2:
		score = n * (d + 1)
	elif winner == 3:
		score = 2 * n * (d + 1)
		
	return score
	
def readScore():
	f=open("scores.txt", "r")
	if f.mode == 'r':
		scores = f.read()	
	return scores
	
def updateScore(scoresInput, newInitials, newScore):
	spaces = 0
	score = ""
	scores = []
	initials = []
	for x in scoresInput:
		if x == " ":
			if spaces == 0:
				initials.append(score)
				score = ""
				spaces = 1
			else:
				scores.append(score)
				score = ""
				spaces = 0
		else: 
			score = score + x
	scores.append(score)
	
	output = ""
	x = 0
	while x < 5:
		if newScore >= int(scores[x]):
			output += newInitials
			output += " "
			output += str(newScore)
			output += " "
			while x < 4:
				output += initials[x]
				output += " "
				output += scores[x]
				output += " "
				x += 1
			x += 1
		else:
			output += initials[x]
			output += " "
			output += scores[x]
			output += " "
			x += 1
			
	f=open("scores.txt", "w")
	if f.mode == 'w':
		f.write(output)
	return output
		
#test1=initials(window, 0)
# test2=initials(window, 1)
# test3=initials(window, 2)

# print("Test 1 initials: " + test1)
# print("Test 2 initials: " + test2)
# print("Test 3 initials: " + test3)
# input1 = input("Do all of the initials match your input? Y/N: ")
# if input1 == "y":
	# print("All tests passed!")
# else:
	# print("Initial input not working")
	
#scores(window, "AA 0 BB 0 CC 0 DD 0 EE 0")

#input2 = input("Did all of the scores and initials print correctly? Y/N: ")
# if input2 == "y":
	# print("All tests passed!")
# else:
	# print("Score output not working")
# x = updateScore(readScore(), "hh", 30)
# scores(window, x)

# score = calcScore(0, 4, 4)	#winner, n, d
# scrs = readScore()
# ins = initials(window, 0)	#window, winner
# scoreString = updateScore(scrs, ins, score)	#high scores, initials, score
# scores(window, scoreString)	#window, high scores
