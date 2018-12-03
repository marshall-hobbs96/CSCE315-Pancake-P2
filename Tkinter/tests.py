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
	



if __name__ == "__main__":	
	splash_tests()
	instruction_tests()
	