import turtle
import random

path = "../두근두근파이썬_강의자용/sources/chap05/"

screen = turtle.Screen()

image1 = path + "front.GIF"
image2 = path + "back.GIF"

screen.addshape(image1)
screen.addshape(image2)

t1 = turtle.Turtle()

while True:
    if input() != "":
        break

    coin = random.randint(0, 1)
    if coin == 0:
        t1.shape(image1)
        t1.stamp()
    else:
        t1.shape(image2)
        t1.stamp()