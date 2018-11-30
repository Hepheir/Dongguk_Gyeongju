# http://www.freeminesweeper.org/minecore.html

from PIL import Image, ImageGrab, ImageTk
import tkinter as tk
import sys
import math

from pynput.mouse import Button, Controller
mouse = Controller()

isMacOS = False
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

    BLANK = Image.open('asset/blank.gif').convert('RGB')
    BOMB_FLAGGED  = Image.open('asset/bombflagged.gif').convert('RGB')
    BOMB_QUESTION = Image.open('asset/bombquestion.gif').convert('RGB')
    BOMB_DEATH    = Image.open('asset/bombdeath.gif').convert('RGB')
    OPEN_0 = Image.open('asset/open0.gif').convert('RGB')
    OPEN_1 = Image.open('asset/open1.gif').convert('RGB')
    OPEN_2 = Image.open('asset/open2.gif').convert('RGB')
    OPEN_3 = Image.open('asset/open3.gif').convert('RGB')
    OPEN_4 = Image.open('asset/open4.gif').convert('RGB')
    OPEN_5 = Image.open('asset/open5.gif').convert('RGB')
    OPEN_6 = Image.open('asset/open6.gif').convert('RGB')
    OPEN_7 = Image.open('asset/open7.gif').convert('RGB')
    OPEN_8 = Image.open('asset/open8.gif').convert('RGB')


def scanTemplate():
    # Scan the template consisted of 'BLANK's.
    print("Scan template position")
    _TARGET = BLANK

    # Get screen shot
    scr = ImageGrab.grab().convert('RGB')

    if isMacOS:
        # macOS에서 화면 캡쳐시 실제 이미지와 비율이 다른 점을 보정.
        scr.thumbnail((scr.width/2, scr.height/2))

    # As long as all tiles has shares same width and height
    global TILE_WIDTH, TILE_HEIGHT

    TILE_WIDTH  = _TARGET.width
    TILE_HEIGHT = _TARGET.height

    founds = 0

    if isMacOS:
        scan_gapsX = 0.25
        scan_gapsY = 0.25
    else:
        scan_gapsX = 1
        scan_gapsY = 1

    TEMPLATE_MAP = findImg(scr, _TARGET)

    print(TEMPLATE_MAP)

"""
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

            if compSimImage(part, _TARGET):
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
"""


def findImg(fromImg, findImg):
    # 큰 비율로 압축된 이미지 -> 적은 비율 ""로 조금씩 비교해 감.
    _map = [
        (0, 0),
        (fromImg.width-TILE_WIDTH, fromImg.height-TILE_HEIGHT)
    ]

    for lv in [1, 2, 4, 8, 16]:
        _from = fromImg
        _find = findImg
        _from.thumbnail((
            _from.width/(TILE_WIDTH/lv),
            _from.height/(TILE_HEIGHT/lv)
        ))
        _find.thumbnail((
            _find.width/(TILE_WIDTH/lv),
            _find.height/(TILE_HEIGHT/lv)
        ))

        _from.crop((
            _map[0][0], _map[0][1],
            _map[-1][0]+(TILE_WIDTH/lv), _map[-1][1]+(TILE_HEIGHT/lv)
        ))

        _m = _findImg(_from, _find)

        if not _m[0]:
            # If nothing found, stop searching.
            break
        else:
            _map = _m

    return _map

def _findImg(fromImg, findImg):
    _map = []

    pix1 = fromImg.load()
    pix2 = findImg.load()

    for x in range(fromImg.width):
        for y in range(fromImg.height):
            if getPixelErrRate(pix1[x, y], pix2[0, 0]) < 2:
                # findImg의 0, 0위치 픽셀과 거의 일치하는 픽셀이 발견되면,
                # 해당 픽셀로 부터 findImg.width * findImg.height 범위의
                # 픽셀을 비교한다.
                isEqual = True
                for sX in range(findImg.width):
                    for sY in range(findImg.height):
                        if getPixelErrRate(pix1[x+sX, y+sY], pix2[sX, sY]) >= 2:
                            isEqual = False
                            break
                    if not isEqual:
                        break
                if isEqual:
                    _map.append((x, y))
    return _map


def getPixelErrRate(pix1, pix2):
    (r1, g1, b1) = pix1
    (r2, g2, b2) = pix2

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