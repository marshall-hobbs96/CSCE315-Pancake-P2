from Tkinter import *
from player_turn import *
from ai_turn import *
from win_window import *
from random import *
from lose_window import *
from scores import *
import sys

def calc_AI_move(ai_stack):
	n = len(ai_stack)	
	ans = n
	i = n-1
	
	while (ai_stack[i] == str(ans)):
		ans-=1
		i-=1
	
	if (ai_stack[0] == str(ans)): # if top
		#print("in if top")
		return str(ans)
	else:
		#print("in else")
		pnum = ans	

	loc = ai_stack.index(str(pnum)) + 1
	return str(loc)
    
def main():
    print('test')
    arg = sys.argv[1]
    stack = str(arg)
    player_stack = stack
    ai_stack = stack
    in_order_stack = "123456789"
    stack_size = len(stack);
    window = Tk()
    window.geometry("1280x720")
    print(in_order_stack[0:stack_size])
    result = 2 #0 = loss, 1 = win, 2 = tie
    game_done = 0
    while(game_done != 1):
        player_stack = player_turn(player_stack, ai_stack, window)
        ai_stack = ai_turn(player_stack, ai_stack, calc_AI_move(ai_stack), window)


        if player_stack[::-1] == in_order_stack[0:stack_size] and ai_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 2
            tie_window(window)
        elif player_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 1
            win_window(window)
        elif ai_stack[::-1] == in_order_stack[0:stack_size]:
            game_done = 0
            lose_window(window)

    score = calcScore(result, 4, 4)
    scrs = readScore()
    ins = initials(window, 0)
    score_string = updateScore(scrs, ins,score)
    scores(window,score_string)
            
if __name__ == "__main__":
    main()

