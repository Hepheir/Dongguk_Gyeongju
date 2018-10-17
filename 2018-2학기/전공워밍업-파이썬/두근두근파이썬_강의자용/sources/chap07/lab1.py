import turtle 

t = turtle.Turtle()
t.shape("turtle")

def square(length):		# length는 한변의 길이
	for i in range(4):
		t.forward(length)
		t.left(90)

t.up()				# 펜을 든다. 
t.goto(-200, 0)		# (-200, 0)으로 이동한다. 
t.down()			# 펜을 내린다. 
square(100);			# square() 함수를 호출한다. 

t.up()
t.goto(0, 0)
t.down()
square(100);

t.up()
t.goto(200, 0)
t.down()
square(100);
