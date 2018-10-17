from tkinter import *
import time
import random

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
        (x1, y1, x2, y2) = self.canvas.coords(self.id)	# 공의 현재 위치를 얻는다. 
        (self.x, self.y) = (x1, y1)
        if x1 <= 0 or x2 >= WIDTH:  # 공의 x좌표가 음수이거나 x좌표가 오른쪽 경계를 넘으면
            self.xspeed = - self.xspeed		# 속도의 부호를 반전시킨다. 
        if y1 <= 0 or y2 >= HEIGHT:  # 공의 y좌표가 음수이거나 y좌표가 아래쪽 경계를 넘으면
            self.yspeed = - self.yspeed		# 속도의 부호를 반전시킨다.
WIDTH = 800		# 윈도우의 가로 크기를 저장한다. 
HEIGHT = 400		# 윈도우의 세로 크기를 저장한다. 

window = Tk()
canvas = Canvas(window, width=WIDTH, height=HEIGHT)
canvas.pack()

color_list = [ "yellow", "green", "blue", "red", "orange", "pink", "grey", "black" ]
# 공들이 저장되는 리스트를 만든다. 
balls_list = []

# 10번 반복하면서 Ball 클래스의 객체를 생성하여 리스트에 저장한다.
for i in range(10):
    color = random.choice(color_list)
    size = random.randrange(10, 100)
    xspeed = random.randrange(1, 10)
    yspeed = random.randrange(1, 10)
    balls_list.append(Ball(canvas, color, size, 0, 0, xspeed, yspeed))
    
# 리스트에 저장된 각각의 공들을 이동시킨다. 
while True:
    for ball in balls_list:
        ball.move()
    window.update()
    time.sleep(0.03)            
