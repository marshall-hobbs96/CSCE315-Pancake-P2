from Tkinter import *
from player_turn import *
from ai_turn import *
from win_window import *
from random import *
from lose_window import *
from tie_window import *
from scores import *
import sys


def calc_AI_move(ai_stack):
	n = len(ai_stack)	
	ans = n
	i = 0
	
	while (ai_stack[i] == str(ans)):
		#print("checking: ", ans)
		ans-=1
		i+=1
	
	#print(ai_stack[n-1])
	#print(ans)
	
	if (ai_stack[n-1] == str(ans)): # if top
		#print("in if top")
		return str(ans)
	else:
		#print("in else")
		pnum = ans
	
	#print("pancake number: ", pnum)	
 	loc = ai_stack.index(str(pnum)) + 1
 	loc = n-(loc-1)
	#print("location: ", loc)
	return str(loc)
	#return str(ai_stack.index(pnum))


def main():

    
    
    #print('test')
    arg = sys.argv[1]
    stack = str(arg)
    player_stack = stack
    ai_stack = stack
    in_order_stack = "123456789"
    stack_size = len(stack);
    window = Tk()
    window.geometry("1280x720")
    result = 2 #0 = loss, 1 = win, 2 = tie
    game_done = 0
    status = -1
    while(game_done != 1):
        whatflip = calc_AI_move(ai_stack)
        player_stack = player_turn(player_stack, ai_stack, window)
        ai_stack = ai_turn(player_stack, ai_stack, whatflip, window)

        if player_stack[::-1] == in_order_stack[0:stack_size] and ai_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            tie_window(window)
            result = 2
            status = 2
            #print result
        elif player_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            win_window(window)
            result = 3
            status = 1
            #print result
        elif ai_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            lose_window(window)
            result = 1
            status = 0
            #print result

    f=open("param.txt","r")
    if f.mode == 'r':
        nd = f.read()
    n = int(nd[0])
    d = int(nd[1])
    score = calcScore(result, n, d)
    scrs = readScore()
    ins = initials(window, status)
    f=open("initials.txt","r")
    if f.mode == 'r':
        ins = f.read()
    score_string = updateScore(scrs, ins,score)
    scores(window,score_string)
            
if __name__ == "__main__":
    main()

