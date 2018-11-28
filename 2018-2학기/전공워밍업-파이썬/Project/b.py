from PIL import Image, ImageGrab, ImageTk
import tkinter as tk
import sys
import math

isMacOS = True
isDebug = True

MAX_ERROR_RATE = 0.00001

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

    TILE_WIDTH  = BLANK.width
    TILE_HEIGHT = BLANK.height

    if isDebug:
        printImgInit() # TEST
        printImg(scr)

    founds = 0 # debug
    minEr = 10000 # debug
    
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

            # printImg(part)

            debugEr = compSimImage(part, BLANK)
            if minEr > debugEr:
                minEr = debugEr

            # if compSimImage(part, BLANK):
            #     print("Found!")
            #     founds += 1

            # Print scanning progress state.
            progress =  (scrX * scr.height + scrY) / (scr.width * scr.height) * 100
            sys.stdout.write("Scanning progress: %.6f%%" % (progress) )
            sys.stdout.flush()
    print("")
    print("Scanning finished")
    print("total", founds, "blocks found")

def compImg(img1, img2):
    # Compare two images that are cropped. (or not)
    px1 = img1.load()
    px2 = img2.load()
    for x in range(img1.width):
        for y in range(img1.height):
            if not px1[x, y] == px2[x, y]:
                return False
    return True

def compSimImage(img1, img2):
    # Compare two images and return whether they are simillar or not.
    
    _COMP_BOX = (4, 4) # 분할하여 비교할 영역의 너비, 높이

    for bX in range(0, img1.width, _COMP_BOX[0]):
        for bY in range(0, img1.height, _COMP_BOX[1]):
            box = (
                bX,
                bY,
                bX + _COMP_BOX[0] - 1,
                bY + _COMP_BOX[1] - 1
            )
            errorRate = getImgErrRate(
                img1.crop(box),
                img2.crop(box)
            )

            if errorRate >= MAX_ERROR_RATE:
                print("e.r. : ", errorRate)
                return errorRate # False
    return True
    
    

def getImgErrRate(img1, img2):
    (r1, g1, b1) = meanImg(img1)
    (r2, g2, b2) = meanImg(img2)

    err_rate = math.sqrt(
        pow((r1-r2), 2)+
        pow((g1-g2), 2)+
        pow((b1-b2), 2)
    )

    return err_rate

def meanImg(image):
    # 이미지 내의 모든 픽셀의 rgb값의 분산을 구함
    pix = image.convert('RGB').load()
    R = 0
    G = 0
    B = 0
    for x in range(image.width):
        for y in range(image.height):
            r, g, b = pix[x, y]
            R += r
            G += g
            B += b

    n_of_pixels = image.width * image.height

    R /= n_of_pixels
    B /= n_of_pixels
    G /= n_of_pixels

    return (R, B, G)

def scanTile(x, y):
    pass

main()