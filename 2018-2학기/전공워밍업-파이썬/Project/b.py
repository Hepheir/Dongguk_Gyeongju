from PIL import Image, ImageGrab, ImageTk
import tkinter as tk
import sys
import math

from pynput.mouse import Button, Controller
mouse = Controller()

isMacOS = True
isDebug = True

MAX_ERROR_RATE = 6.2

DEBUG_min_error_rate2 = 10000
DEBUG_min_error_rate = 10000

TEMPLATE_MAP = []

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
    # Scan the template consisted of 'BLANK's.
    print("Scan template position")
    _START_TILE = BLANK

    # Get screen shot
    scr = ImageGrab.grab()

    if isMacOS:
        # macOS에서 화면 캡쳐시 실제 이미지와 비율이 다른 점을 보정.
        scr.thumbnail((scr.width/2, scr.height/2), Image.ANTIALIAS)

    # As long as all tiles has shares same width and height
    global TILE_WIDTH, TILE_HEIGHT

    TILE_WIDTH  = _START_TILE.width
    TILE_HEIGHT = _START_TILE.height

    founds = 0

    if isMacOS:
        scan_gapsX = 0.25
        scan_gapsY = 0.25
    else:
        scan_gapsX = 1
        scan_gapsY = 1

    scrX = 0
    while scrX < scr.width:
        scrY = 0
        while scrY < scr.height:
    # for scrX in range(16, 520, scrX_gaps):
    #     for scrY in range(140, 408, scrY_gaps):
            sys.stdout.write("\r")
            part = scr.crop((
                scrX,
                scrY,
                scrX+TILE_WIDTH,
                scrY+TILE_HEIGHT
            ))

            if compSimImage(part, _START_TILE):
                # If tile is found, append the tile data to the TEMPLATE_MAP
                TEMPLATE_MAP.append((scrX, scrY))
                founds += 1

            # Print scanning progress state.
            progress = 100 * (scrX * scr.height + scrY) / (scr.width * scr.height)
            sys.stdout.write("Scanning progress: %.6f%%\tFounds: %d" % (progress, founds) )
            sys.stdout.flush()

        # If a TILE has been found, there's no need to search every single pixels.
            if founds:
                scan_gapsY = TILE_HEIGHT
            scrY += scan_gapsY
        if founds:
            scan_gapsX = TILE_WIDTH
        scrX += scan_gapsX
    print("")
    print("Scanning finished")
    print("total", founds, "blocks found")

    global DEBUG_min_error_rate, DEBUG_min_error_rate2
    print("min Err Rate was : ", DEBUG_min_error_rate)
    print("  2nd : ", DEBUG_min_error_rate2)

def compImg(img1, img2):
    # Compare two images that are cropped. (or not)
    px1 = img1.load()
    px2 = img2.load()
    for x in range(img1.width):
        for y in range(img1.height):
            if not px1[x, y] == px2[x, y]:
                return False
    return True

def compSimImage(img1, img2, allowedErrorRate=MAX_ERROR_RATE):
    # Compare two images and return whether they are simillar or not.
    _COMP_BOX = (2, 2) # 분할하여 비교할 영역의 너비, 높이

    boxes = 0
    dErrorRate = 0
    for bX in range(0, img1.width, _COMP_BOX[0]):
        for bY in range(0, img1.height, _COMP_BOX[1]):
            box = (
                bX,
                bY,
                bX + _COMP_BOX[0] - 1,
                bY + _COMP_BOX[1] - 1
            )
            dErrorRate += getImgErrRate(
                img1.crop(box),
                img2.crop(box)
            )
            boxes += 1

    meanErrorRate = dErrorRate / boxes

    # Debug
    global DEBUG_min_error_rate , DEBUG_min_error_rate2
    if DEBUG_min_error_rate > meanErrorRate:
        DEBUG_min_error_rate2 = DEBUG_min_error_rate
        DEBUG_min_error_rate = meanErrorRate

    return meanErrorRate <= allowedErrorRate
    

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