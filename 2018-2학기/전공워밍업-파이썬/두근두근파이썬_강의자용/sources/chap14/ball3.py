from tkinter import *
	
WIDTH = 800		# 윈도우의 가로 크기를 저장한다. 
HEIGHT = 400		# 윈도우의 세로 크기를 저장한다. 

window = Tk()
canvas = Canvas(window, width=WIDTH, height=HEIGHT)
canvas.pack()

canvas.create_oval(100, 100, 60, 60, fill="red")	# 원을 하나 그린다.  
