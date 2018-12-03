from Tkinter import *
from PIL import ImageTk, Image
import functions as f

if __name__ == "__main__":	
	f.splash()
	test1 = input("Did the splash screen display properly with the background image and team names? (y/n)")
	if test1 == 'y':
		print("Test 1: Pass")
	else:
		print("Test 1: FAIL!")
	