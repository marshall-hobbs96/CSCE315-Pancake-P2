from Tkinter import *
from PIL import ImageTk, Image
from random import shuffle
import tkMessageBox


inputStack = list()
finalStack = list()
output_x = 500

def setStack(w):
	global finalStack
	stack = ''.join(str(e) for e in finalStack)
	fd = open("stack.dat","w")
	fd.write(stack)
	fd.close
	w.quit()
	w.pack_forget()
	

def generateStack(stackSize, stackState,w):
	global finalStack
	del finalStack[:]
	numbers = [0,0,0,0,0,0,0,0,0]                           
	for i in stackState:		              #iterate through the user input string
		if((i >= 0) and (i <= 9)):                   
			finalStack.append(i)
			numbers[i - 1] += 1
			if(numbers[i - 1] > 1):
				for i in xrange(stackSize):
					finalStack.append(i + 1)             #fill with 1 - n for shuffle
				tkMessageBox.showwarning("Warning","Since the order entered has duplicate numbers, the game is going to create a random stack")
				gen_rand_stack(finalStack, stackSize, w)   #shuffle the stack, i.e. random
				return
			elif(i > stackSize):
				for i in xrange(stackSize):
					finalStack.append(i + 1)              #fill with 1 - n for shuffle
				tkMessageBox.showwarning("Warning","Since you entered a number higher than the size of the stack, the game is going to create a random stack")
				gen_rand_stack(finalStack, stackSize, w)     #shuffle the stack, i.e. random
				return
	if (len(finalStack) != (stackSize)):         #stacksize is 5 and user put 1 2 3 4 or something like that
		del finalStack[:]
		for i in xrange(stackSize):
			finalStack.append(i + 1)              #fill with 1 - n for shuffle
		tkMessageBox.showwarning("Warning","Since the wrong number of inputs were entered, the game is going to create a random stack")
		gen_rand_stack(finalStack, stackSize, w)		#shuffle the stack, i.e. random
		return
	finalStack = stackState
	setStack(w)
	return
	

def gen_rand_stack(stack, stackSize,w):
	not_shuffled = 1
	resultStack = stack 
	while(not_shuffled):
		shuffle(stack)              #shuffle the stack
		for i in xrange(stackSize):
			if(stack[i]==(stackSize-i)):
				not_shuffled = 1
			else:
				not_shuffled = 0
	finalStack = resultStack
	setStack(w)
	return
	

def addToStack(p,w,b):
	global inputStack
	global output_x
	inputStack.append(p)
	output = str(p)
	w.create_text(output_x,325,text=output,font=("Arial",20), anchor = NW,tag = "output")
	b.config(state=DISABLED,takefocus=0)
	output_x = output_x+20
	
def drawPancakeButtons(w, n):

	pb1 = Button(w, text="1", command=lambda:addToStack(1,w,pb1), height=2, width=5)
	pb2 = Button(w, text="2", command=lambda:addToStack(2,w,pb2), height=2, width=5)
	pb3 = Button(w, text="3", command=lambda:addToStack(3,w,pb3), height=2, width=5)
	pb4 = Button(w, text="4", command=lambda:addToStack(4,w,pb4), height=2, width=5)
	pb5 = Button(w, text="5", command=lambda:addToStack(5,w,pb5), height=2, width=5)
	pb6 = Button(w, text="6", command=lambda:addToStack(6,w,pb6), height=2, width=5)
	pb7 = Button(w, text="7", command=lambda:addToStack(7,w,pb7), height=2, width=5)
	pb8 = Button(w, text="8", command=lambda:addToStack(8,w,pb8), height=2, width=5)
	pb9 = Button(w, text="9", command=lambda:addToStack(9,w,pb9), height=2, width=5)
	
	step = 780/n
	
	coord = range(280,1100,step)
	
	for i in xrange(n+1):
		if (i == 1):
			pb1.place(x=coord[i-1],y=200)
		elif (i == 2):
			pb2.place(x=coord[i-1],y=200)
		elif (i == 3):
			pb3.place(x=coord[i-1],y=200)
		elif (i == 4):
			pb4.place(x=coord[i-1],y=200)
		elif (i == 5):
			pb5.place(x=coord[i-1],y=200)
		elif (i == 6):
			pb6.place(x=coord[i-1],y=200)
		elif (i == 7):
			pb7.place(x=coord[i-1],y=200)
		elif (i == 8):
			pb8.place(x=coord[i-1],y=200)
		elif (i == 9):
			pb9.place(x=coord[i-1],y=200)

def drawRandomButton(w, n):
	global finalStack
	for i in xrange(n):
		finalStack.append(i + 1)                 #fill with 1 - n for shuffle	
	rb = Button(w, text="Random", command=lambda:gen_rand_stack(finalStack, n, w), height=3, width=10)
	rb.place(x=350,y=500)
	
	
def drawSubmitButton(w, n):
	global inputStack
	sb = Button(w, text="Submit", command=lambda:generateStack(n, inputStack, w), height=3, width=10)
	sb.place(x=650,y=500)
	

def drawOrderWindow(master,n):
	
	w = Canvas(master, width=1280, height=720)
	w.pack()
	n = int(n)
	w.create_text(450,50,text="Pick the order of your pancake!",font=("Arial",26), anchor = NW)
	w.create_text(350,125,text="Press the buttons in the order you want or click Random",font=("Arial",20), anchor = NW)
	drawPancakeButtons(w, n)
	drawRandomButton(w, n)	
	drawSubmitButton(w, n)
	w.mainloop()
	
	fd = open("stack.dat","r")
	pancakeStack = fd.readline()
	return int(pancakeStack)
			
def setND(w,n,d):
	fd = open("param.dat","w")
	fd.write(str(n))
	fd.write(str(d))
	fd.close
	w.quit()
	w.pack_forget()

def choosePancakes (w):
	w.create_text(500,160,text="Select Number of Pancakes:",font=("Arial",20), anchor = NW)
	
	pancakeScale = Scale(w, from_ = 2, to = 9, tickinterval = 1, length = 1000, orient=HORIZONTAL, sliderlength = 30, font=("Arial",25))
	pancakeScale.place(x=150,y=200)
	
	nextB = Button(w, text="Next", command=lambda:chooseDifficulty(w, pancakeScale, pancakeScale.get()), height=3, width=10)
	nextB.place(x=600,y=350)	
	
def chooseDifficulty(w,p,n):
	p.config(state=DISABLED,takefocus=0) # locks numOfPancakes input to avoid invalid values
	w.create_text(500,460,text="Select Difficulty:",font=("Arial",20), anchor = NW)
	diffScale = Scale(w, from_ = 1, to = n, tickinterval = 1, length = 1000, orient=HORIZONTAL, sliderlength = 30, font=("Arial",25))
	diffScale.place(x=150,y=500)
	
	submitB = Button(w, text="Submit", height=3, width=10, command=lambda:setND(w,n,diffScale.get()))
	submitB.place(x=600,y=650)
	
	
def drawDifficultyWindow(master):
	global numOfPancakes
	global difficulty
	
	w = Canvas(master, width=1280, height=720)
	w.pack()
	w.create_text(520,50,text="Set Your Difficulty!",font=("Arial",30), anchor = NW)
	
	choosePancakes(w)
	w.mainloop()
	
	fd = open("param.dat","r")
	parameters = fd.readline()
	return int(parameters)
	

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
	window.title("Pretty Pancake!")
	wind_width = 1280
	wind_height = 720
	c = Canvas(window, width = wind_width, height = wind_height)
	c.pack(expand = YES, fill = BOTH)
	button = Button(window,text = "START", command=window.quit)
	button.configure(width = 20, height = 5)
	c.create_window(1000,600, window = button)
	pic = ImageTk.PhotoImage(Image.open("Pancake.jpg"))
	c.create_image(0,0, image = pic, anchor= NW)
	print("Running. Use graphics window to play.")
	window.mainloop()	
	c.pack_forget()
	instructions(window)
	