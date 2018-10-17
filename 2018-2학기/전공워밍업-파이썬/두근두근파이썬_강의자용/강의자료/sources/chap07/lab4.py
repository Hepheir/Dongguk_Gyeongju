import turtle			# 터틀 그래픽 모듈을 포함한다. 

def draw(x, y):
    t.goto(x, y)

t = turtle.Turtle()
t.shape("turtle")
t.pensize(10)
s = turtle.Screen()		# 그림이 그려지는 화면을 얻는다. 
s.onscreenclick(draw)		# 마우스 클릭 이벤트 처리 함수를 등록한다. 
