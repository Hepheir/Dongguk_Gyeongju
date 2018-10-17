import turtle
t = turtle.Turtle()
t.shape("turtle")
t.color("red")
t.stamp()
move = 30
for i in range(12):			# 12번 반복
	t.penup()			# 펜을 올린다. 
	t.forward(50)			# 50만큼 전진
	t.pendown()			# 펜을 내린다. 
	t.forward(25)
	t.penup()
	t.forward(15)
	t.stamp()
	t.home()
	t.right(move)
	move = move+30  
