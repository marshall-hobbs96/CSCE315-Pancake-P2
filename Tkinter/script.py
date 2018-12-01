from Tkinter import *
def printTest():
	sys.argv = ["Main"]
	window = Tk()
	window.title("Discrepency")
	wind_width = 1200
	wind_height = 800
	c = Canvas(window, width = wind_width, height = wind_height)
	c.pack()
	window.mainloop()
	return 5
	