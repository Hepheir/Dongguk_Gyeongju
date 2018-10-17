from turtle import *    # turtle 모듈에서 모든 것을 불러온다.

class MyTurtle(Turtle):
    def glow(self,x,y):
        self.fillcolor("red")

turtle = MyTurtle()
turtle.shape("turtle")
turtle.onclick(turtle.glow)     # 거북이를 클릭하면 색상이 빨강색으로 변경된다. 
