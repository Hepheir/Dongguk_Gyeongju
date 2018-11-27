# http://www.freeminesweeper.org/minecore.html

from PIL import Image, ImageGrab, ImageDraw, ImageTk
import tkinter as tk

from pynput.mouse import Button, Controller

import math

mouse = Controller()

def searchTemplate():
    # get Boundaries of the template
    input("지뢰찾기 판의 왼쪽 위 칸위에 커서를 올려주세요.")
    (leftTopX, leftTopY) = mouse.position

    input("지뢰찾기 판의 오른쪽 아래 칸위에 커서를 올려주세요.")
    (rightBottomX, rightBottomY) = mouse.position

    # if, Darwin(Mac OS), screen choordination is
    # as double as pixel choordinations
    if input("is Mac OS? (y/n)") == 'y':
        leftTopX *= 2
        leftTopY *= 2
        rightBottomX *= 2
        rightBottomY *= 2
    
    # set variables
    selected_width = (rightBottomX - leftTopX)
    selected_height = (rightBottomY - leftTopY)
    selected_box = (
        leftTopX,     leftTopY,
        rightBottomX, rightBottomY
    )

    # Capture the template
    selected_img = ImageGrab.grab(bbox=selected_box)

    # Pixel Access
    pix_tempImg = selected_img.load()
    
    # Search for the tile pattern
    hor = []
    for i in range(int(selected_width)):
        hor.append(pix_tempImg[i, 0])
    ver = []
    for i in range(int(selected_height)):
        ver.append(pix_tempImg[0, i])

    pattern_width = findPattern(hor)
    pattern_height = findPattern(ver)
    patterns = [
        math.ceil(selected_width / pattern_width),
        math.ceil(selected_height / pattern_height)
    ]

    print("Pattern found : ", pattern_width, pattern_height, patterns)

    # Resize the canvas
    map_width = selected_width + (2 * pattern_width)
    map_height = selected_width + (2 * pattern_height)
    map_box = (
        leftTopX - pattern_width,
        leftTopY - pattern_height,
        rightBottomX + pattern_width,
        rightBottomY + pattern_height
    )

    # Test : Feedback
    template_img = ImageGrab.grab(map_box)

    # Draw circle outlines to show recognized hitpoints.
    draw = ImageDraw.Draw(template_img)
    radius = 3
    for x in range(pattern_width, int(map_width), pattern_width):
        for y in range(pattern_height, int(map_height), pattern_height):
            draw.ellipse((
                (x - radius, y - radius),
                (x + radius, y + radius)
            ), None, 'red')

    window = tk.Tk()
    canvas = tk.Canvas(window, width=map_width, height=map_height)
    canvas.pack()
    tk_img = ImageTk.PhotoImage(template_img)
    canvas.create_image(map_width/2, map_height/2, image=tk_img)

    window.mainloop() # TEST



def findPattern(li):
    smallest = len(li)
    for i in range(len(li), 0, -1):
        if isRepeatOf(li[0:i], li):
            smallest = i
    return smallest
        
def isRepeatOf(child, parent):
    for i in range(len(parent)):
        if not child[i % len(child)] == parent[i]:
            return False
    return True

searchTemplate()