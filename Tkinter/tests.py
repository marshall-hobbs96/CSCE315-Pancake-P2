from Tkinter import *
from PIL import ImageTk, Image
import functions as f


def splash_tests():
	print("The screen will open, look to see if there is an image of pancakes, six team member names, and a title. Then press the start button.")
	print
	window = f.splash()
	window.destroy()
	test1 = raw_input("Was the an image of pancakes present? (y/n): ")
	test2 = raw_input("Were 6 team member names present? (y/n): ")
	test3 = raw_input("Was there a title present at the top? (y/n): ")
	print
	print("Splash screen tests:")
	if test1 == "y":
		print("Test 1: PASS")
	else:
		print("Test 1: FAIL")
	if test2 == "y":
		print("Test 2: PASS")
	else:
		print("Test 2: FAIL")
	if test3 == "y":
		print("Test 3: PASS")
	else:
		print("Test 3: FAIL")
	print
		
def instruction_tests():

	print("The screen will open, look to see if there is a Goals, Setup, and How to play sections, Instructions is written at the top, and the continue button is centered. Then press the continue button.")
	print
	window= Tk()
	f.instructions(window)
	window.destroy()
	test1 = raw_input("Was there a Goals, Setup, and How to play section? (y/n): ")
	test2 = raw_input("Was instructions written at the top? (y/n): ")
	test3 = raw_input("Was the continue button centered? (y/n): ")
	print
	print("Instruction screen tests:")
	if test1 == "y":
		print("Test 1: PASS")
	else:
		print("Test 1: FAIL")
	if test2 == "y":
		print("Test 2: PASS")
	else:
		print("Test 2: FAIL")
	if test3 == "y":
		print("Test 3: PASS")
	else:
		print("Test 3: FAIL")
	print

def difficultyWindow_tests():
	print("The screen will open, there will be 1 slider initially to choose number of pancakes")
	print("After selecting and pressing 'Next', a second slider with difficulty should be visible")
	print
	window = Tk()
	f.drawDifficultyWindow(window)
	window.destroy()
	test1 = raw_input("Was there a slider for pancakes? (y/n): ")
	test2 = raw_input("Was there a next button? (y/n): ")
	test3 = raw_input("Did the second slider show up when you pressed Next? (y/n): ")
	test4 = raw_input("Were you able to move the sliders around? (y/n): ")

	print
	print("Difficulty window screen tests:")
	if test1 == "y":
		print("Test 1: PASS")
	else:
		print("Test 1: FAIL")
	if test2 == "y":
		print("Test 2: PASS")
	else:
		print("Test 2: FAIL")
	if test3 == "y":
		print("Test 3: PASS")
	else:
		print("Test 3: FAIL")
	if test4 == "y":
		print("Test 4: PASS")
	else:
		print("Test 4: FAIL")
	print
	
def orderWindow_tests():
	print("The screen will open, there will be 7 pancake buttons, press the buttons according to the order you want")
	print
	window = Tk()
	f.drawOrderWindow(window, 7)
	window.destroy()
	test1 = raw_input("Were there 7 different buttons? (y/n): ")
	test2 = raw_input("Was there a random button at the bottom? (y/n): ")
	test3 = raw_input("Was there a submit button at the bottom? (y/n): ")
	test4 = raw_input("Did the buttons disable when you pressed them? (y/n): ")

	print
	print("Order window screen tests:")
	if test1 == "y":
		print("Test 1: PASS")
	else:
		print("Test 1: FAIL")
	if test2 == "y":
		print("Test 2: PASS")
	else:
		print("Test 2: FAIL")
	if test3 == "y":
		print("Test 3: PASS")
	else:
		print("Test 3: FAIL")
	if test4 == "y":
		print("Test 4: PASS")
	else:
		print("Test 4: FAIL")
	print
	
	
def initials_test():
	window = Tk()
	window.geometry('1280x720')
	window.title("Test")
			
	test1=f.initials(window, 0)
	test2=f.initials(window, 1)
	test3=f.initials(window, 2)

	print("Test 1 initials: " + test1)
	print("Test 2 initials: " + test2)
	print("Test 3 initials: " + test3)
	input1 = input("Do all of the initials match your input? Y/N: ")
	if input1 == "y":
		print("All tests passed!")
	else:
		print("Initial input not working")
		
def score_test():
	window = Tk()
	window.geometry('1280x720')
	window.title("Test")

	f.scores(window, "AA 0 BB 0 CC 0 DD 0 EE 0")

	input2 = input("Did all of the scores and initials print correctly? Y/N: ")
	if input2 == "y":
		print("All tests passed!")
	else:
		print("Score output not working")	


if __name__ == "__main__":	
	splash_tests()
	instruction_tests()
	difficultyWindow_tests()
	orderWindow_tests()
	