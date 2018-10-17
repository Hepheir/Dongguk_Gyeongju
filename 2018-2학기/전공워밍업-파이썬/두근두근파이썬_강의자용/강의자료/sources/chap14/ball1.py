class Ball:				
    def __init__(self):		# 생성자
        self.color="red"
        self.size=30
        self.x = 0
        self.y = 0
        self.xspeed = 0
        self.yspeed = 0
    def move(self):			# Ball을 이동시키는 함수
        pass

ball = Ball()

print("공의 색상=", ball.color)
print("공의 크기=", ball.size)
print("공의 x좌표=", ball.x)
