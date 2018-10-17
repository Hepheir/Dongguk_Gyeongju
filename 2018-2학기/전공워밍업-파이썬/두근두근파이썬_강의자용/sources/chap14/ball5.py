from tkinter import *
import time

class Ball:				
    def __init__(self, canvas, color, size, x, y, xspeed, yspeed):	

        self.canvas = canvas		# 캔버스 객체
        self.color = color		# Ball의 색상
        self.size = size		# Ball의 크기
        self.x = x			# Ball의 x좌표
        self.y = y			# Ball의 y좌표

        self.xspeed = xspeed		# Ball의 수평방향 속도
        self.yspeed = yspeed		# Ball의 수직방향 속도
        self.id = canvas.create_oval(x, y, x+size, y+size, fill=color)

    def move(self):			# Ball을 이동시키는 함수
        self.canvas.move(self.id, self.xspeed, self.yspeed)
	
WIDTH = 800		# 윈도우의 가로 크기를 저장한다. 
HEIGHT = 400		# 윈도우의 세로 크기를 저장한다. 

window = Tk()
canvas = Canvas(window, width=WIDTH, height=HEIGHT)
canvas.pack()
ball = Ball(canvas, "red", 30, 0, 0, 10, 0)

while True:		# 메인 루프
    ball.move()
    window.update()
    time.sleep(0.03)
