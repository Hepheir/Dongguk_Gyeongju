from tkinter import *

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
        pass

WIDTH = 800
HEIGHT = 400

window = Tk()
canvas = Canvas(window, width=WIDTH, height=HEIGHT)
canvas.pack()
ballA = Ball(canvas, "red", 30, 0, 0, 0, 0)

input() # Pause