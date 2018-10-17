# 터틀 그래픽을 사용하여야 하므로 다음과 같은 코드를 소스 파일에 입력한다. 
import turtle
t = turtle.Turtle()
t.shape("turtle")

# 사용자로부터 집의 크기를 받아서 size라는 변수에 저장한다. 
# 집의 크기는 정수이므로 input()이 반환하는 문자열을 int()를 통하여 정수로 변환하였다. 
size = int(input("집의 크기는 얼마로 할까요? "))

# 집을 그릴 차례이다. 사각형을 다음과 같은 코드로 그린다. 이때 변수 size를 사용하자. 
# 사각형을 그린다. 
t.forward(size)	# size 만큼 거북이를 전진시킨다. 
t.right(90)		# 거북이를 오른쪽으로 90도 회전시킨다. 
t.forward(size)
t.right(90)
t.forward(size)
t.right(90)
t.forward(size)

# 이제 지붕을 그릴 차례이다. 현재 거북이는 위를 보고 있기 때문에 
# 거북이를 오른쪽으로 90도 회전시켜서 오른쪽을 보도록 한다. 
t.right(90)

# 지붕을 그리면 된다. 지붕은 간단히 삼각형으로 그렸다. 
t.forward(size)
t.left(120)
t.forward(size)
t.left(120)
t.forward(size)
t.left(120)
