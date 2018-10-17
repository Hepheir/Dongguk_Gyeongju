from turtle import *    # turtle 모듈에서 모든 것을 불러온다.

t1 = Turtle()         # 거북이 객체를 생성한다.
t1.shape("circle")

t2 = Turtle()         # 거북이 객체를 생성한다.
t2.shape("turtle")

t3 = Turtle()         # 거북이 객체를 생성한다.
t3.shape("square")

t1.penup()		# 펜을 든다.
t2.penup()
t1.goto(0, 100)	# 거북이를 이동한다.
t2.goto(0, 50)
t1.pendown()		# 펜을 내린다.
t2.pendown()

while True:
    t1.circle(100)	# 원을 그린다. 
    t2.circle(150)
    t3.circle(200)
