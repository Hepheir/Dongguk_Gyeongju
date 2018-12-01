# http://www.freeminesweeper.org/minecore.html

from PIL import Image, ImageGrab, ImageTk, ImageChops
import tkinter as tk
import sys
import math

import sys
import math

from pynput.mouse import Button, Controller
mouse = Controller()

TEMPLATE_MAP = []

def main():
    loadImg()
    scanTemplate()

def openImg(path):
    return Image.open(path).convert('RGB')

def loadImg():
    # Load all required assets
    global ASSET

    print("Load assets")

    class _Asset:
        def __init__(self):
            self.BLANK = openImg('asset/blank.gif')
            self.BOMB_FLAGGED  = openImg('asset/bombflagged.gif')
            self.BOMB_QUESTION = openImg('asset/bombquestion.gif')
            self.BOMB_DEATH    = openImg('asset/bombdeath.gif')
            self.OPEN_0 = openImg('asset/open0.gif')
            self.OPEN_1 = openImg('asset/open1.gif')
            self.OPEN_2 = openImg('asset/open2.gif')
            self.OPEN_3 = openImg('asset/open3.gif')
            self.OPEN_4 = openImg('asset/open4.gif')
            self.OPEN_5 = openImg('asset/open5.gif')
            self.OPEN_6 = openImg('asset/open6.gif')
            self.OPEN_7 = openImg('asset/open7.gif')
            self.OPEN_8 = openImg('asset/open8.gif')

            self.width = self.BLANK.width
            self.height = self.BLANK.height
    ASSET = _Asset()

def getScreenShot(isOS_X=False):
    _scr = ImageGrab.grab().convert('RGB')
    # macOS에서 화면 캡쳐시 실제 이미지와 비율이 다른 점을 보정.
    if isOS_X:
        _scr.thumbnail((_scr.width/2, _scr.height/2))
    return _scr


def scanTemplate():
    # Scan the template consisted of 'BLANK's.
    print("Scan template position")
    scr = getScreenShot(isOS_X=True)
    TEMPLATE_MAP = findImg(scr, ASSET.BLANK)
    print(TEMPLATE_MAP)


def findImg(fromImg, findImg):
    # 큰 비율로 압축된 이미지 -> 적은 비율 ""로 조금씩 비교해 감.
    _map = [
        (0, 0),
        (fromImg.width-ASSET.width, fromImg.height-ASSET.height)
    ]

    for lv in [2, 4, 8, 16]:
        _from = fromImg
        _find = findImg
        _from.thumbnail((
            _from.width/(ASSET.width/lv),
            _from.height/(ASSET.height/lv)
        ))
        _find.thumbnail((
            _find.width/(ASSET.width/lv),
            _find.height/(ASSET.height/lv)
        ))

        _from.crop((
            _map[0][0], _map[0][1],
            _map[-1][0]+(ASSET.width/lv), _map[-1][1]+(ASSET.height/lv)
        ))

        _m = _findImg(_from, _find)

        if len(_m) == 0:
            # If nothing found, stop searching.
            print("found nothing at lv %d" % lv)
            break
        else:
            _map = _m

    return _map

def _findImg(fromImg, findImg):
    print(ImageChops.difference(fromImg, findImg))
    return
    _map = []

    pix1 = fromImg.load()
    pix2 = findImg.load()

    for x in range(fromImg.width):
        for y in range(fromImg.height):
            if getPixelErrRate(pix1[x, y], pix2[0, 0]) < 2:
                print("")
                print("Oh!")
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
            progress = 100 * (x * fromImg.height + y) / (fromImg.width * fromImg.height)
            sys.stdout.write("Scanning progress: %.6f%%\r" % (progress) )
            sys.stdout.flush()
    print("")
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


main()