import turtle
import random
import math

player = turtle.Turtle()
player.color("blue")
player.shape("turtle")
player.penup()
player.speed(0)
screen = player.getscreen()

n_of_asteroids = 100
asteroids = []
for i in range(n_of_asteroids):
    a1 = turtle.Turtle()
    a1.color("red")
    a1.shape("circle")
    a1.penup()
    a1.speed(0)
    a1.goto(random.randint(-300, 300), random.randint(-300, 300))
    asteroids.append(a1)

def turnleft():
    player.left(30)

def turnright():
    player.right(30)

screen.onkeypress(turnleft, "Left")
screen.onkeypress(turnright, "Right")
screen.listen()

def play():
    for a in asteroids:
        player.forward(1)
        a.right(random.randint(-180, 180))
        a.forward(2)
    screen.ontimer(play, 10)
    
screen.ontimer(play, 10)



input()