class Ball:				
    def __init__(self, color, size, x, y, xspeed, yspeed):	# 생성자
        self.color = color		# Ball의 색상
        self.size = size		# Ball의 크기
        self.x = x			# Ball의 중심점의 x좌표
        self.y = y			# Ball의 중심점의 y좌표
        self.xspeed = xspeed		# Ball의 수평방향 속도
        self.yspeed = yspeed		# Ball의 수직방향 속도

    def move(self):			# Ball을 이동시키는 함수
        pass


ballA = Ball("red", 30, 0, 0, 0, 0)
print("공의 색상=", ballA.color)
print("공의 크기=", ballA.size)
print("공의 x좌표=", ballA.x)

print("")

ballB = Ball("blue", 100, 50, 50, 10, 10)

print("공의 색상=", ballB.color)
print("공의 크기=", ballB.size)
print("공의 x좌표=", ballB.x)
