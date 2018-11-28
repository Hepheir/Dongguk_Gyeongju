from PIL import Image, ImageGrab

from PIL import ImageTk
import tkinter as tk

import sys

isMacOS = True

def printImgInit():
    global window, canvas
    window = tk.Tk()
    canvas = tk.Canvas(window, width=TILE_WIDTH, height=TILE_HEIGHT)
    canvas.pack()

def printImg(image):
    tk_img = ImageTk.PhotoImage(image)
    canvas.create_image(TILE_WIDTH/2, TILE_HEIGHT/2, image=tk_img)
    window.update()

def main():
    # Load all required assets
    loadImg()
    scanTemplate()

def loadImg():
    global BLANK
    global BOMB_FLAGGED, BOMB_QUESTION, BOMB_DEATH
    global OPEN_0, OPEN_1, OPEN_2, OPEN_3, OPEN_4
    global OPEN_5, OPEN_6, OPEN_7, OPEN_8
    
    print("Load assets")

    BLANK = Image.open('asset/blank.gif')
    BOMB_FLAGGED  = Image.open('asset/bombflagged.gif')
    BOMB_QUESTION = Image.open('asset/bombquestion.gif')
    BOMB_DEATH    = Image.open('asset/bombdeath.gif')
    OPEN_0 = Image.open('asset/open0.gif')
    OPEN_1 = Image.open('asset/open1.gif')
    OPEN_2 = Image.open('asset/open2.gif')
    OPEN_3 = Image.open('asset/open3.gif')
    OPEN_4 = Image.open('asset/open4.gif')
    OPEN_5 = Image.open('asset/open5.gif')
    OPEN_6 = Image.open('asset/open6.gif')
    OPEN_7 = Image.open('asset/open7.gif')
    OPEN_8 = Image.open('asset/open8.gif')


def scanTemplate():
    # Scan the template consisted of 'open0's.

    print("Scan template position")

    scr = ImageGrab.grab()
    if isMacOS:
        scr.thumbnail((scr.width/2, scr.height/2), Image.ANTIALIAS)

    # As long as all tiles has shares same width and height
    global TILE_WIDTH, TILE_HEIGHT

    TILE_WIDTH  = OPEN_0.width
    TILE_HEIGHT = OPEN_0.height

    ratio = OPEN_0.width / TILE_WIDTH
    print(ratio)


    printImgInit() # TEST
    printImg(scr)
    
    # Screen이 너무 넓어 스캔과정이 오래 걸리기에 일시적으로 스캔 영역을 제한하여둠
    for scrX in range(17, 521): # scr.width
        for scrY in range(142, 408): # scr.height
            sys.stdout.write("\r")
            part = scr.crop((
                scrX,
                scrY,
                scrX+TILE_WIDTH,
                scrY+TILE_HEIGHT
            ))

            printImg(part)

            if compImg(part, OPEN_0):
                print("Found!")

            # Print scanning progress state.
            progress =  (scrX * scr.height + scrY) / (scr.width * scr.height) * 100
            sys.stdout.write("Scanning progress: %.6f%%" % (progress) )
            sys.stdout.flush()
    print("")
    print("Scanning finished")

def compImg(img1, img2):
    # Compare two images that are cropped. (or not)
    px1 = img1.load()
    px2 = img2.load()
    for x in range(img1.width):
        for y in range(img1.height):
            if not px1[x, y] == px2[x, y]:
                return False
    return True

def sigImg(image):
    # 이미지 내의 모든 픽셀의 rgb값의 분산을 구함
    pix = image.load()
    R = 0
    G = 0
    B = 0
    for x in range(image.width):
        for y in range(image.height):
            (r, b, g) = pix[x, y]
            R += r
            B += b
            G += g
    
    


def scanTile(x, y):
    pass

main()