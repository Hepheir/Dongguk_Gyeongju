import turtle
t = turtle.Turtle()
t.shape("turtle")

color_list = ["yellow", "red", "blue", "green"]

for i in range(0, 4):
    t.fillcolor(color_list[i])
    t.begin_fill()
    t.circle(100)
    t.end_fill()

    t.forward(50)

input()
