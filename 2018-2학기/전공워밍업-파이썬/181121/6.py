from tkinter import *
import time

class Ball:
    def __init__(self, canvas, color, size, x, y, xspeed, yspeed):
        self.canvas = canvas
        self.color = color
        self.size = size
        self.x = x
        self.y = y
        self.xspeed = xspeed
        self.yspeed = yspeed
        self.id = canvas.create_oval(x, y, x+size, y+size, fill=color)

    def move(self):
        self.canvas.move(self.id, self.xspeed, self.yspeed)

WIDTH = 800
HEIGHT = 400

window = Tk()
canvas = Canvas(window, width=WIDTH, height=HEIGHT)
canvas.pack()
ball = Ball(canvas, "red", 30, 20, 20, 10, 0)

i = 0
while True:
    if (i < 50):
        i += 1
    else:
        ball.xspeed *= -1
        i = 0
    ball.move()
    window.update()
    time.sleep(0.03)

input() # Pause