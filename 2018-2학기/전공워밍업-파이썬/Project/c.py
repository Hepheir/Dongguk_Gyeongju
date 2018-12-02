# http://www.freeminesweeper.org/minecore.html

import cv2
import numpy as np
from matplotlib import pyplot as plt

import sys
import math

from pynput.mouse import Button, Controller
mouse = Controller()

TEMPLATE_MAP = []

def main():
    loadImg()
    scanTemplate()

def openImg(path):
    return cv2.imread(path, 0)

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
    ASSET = _Asset()

def scanTemplate():        
    img = openImg('asset/blank.gif')
    img2 = img
    template = openImg('capture.gif')
    w, h = template.shape[::-1]

    # All the 6 methods for comparison in a list
    methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
                'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']

    for meth in methods:
        img = img2.copy()
        method = eval(meth)

        # Apply template Matching
        res = cv2.matchTemplate(img,template,method)
        min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

        # If the method is TM_SQDIFF or TM_SQDIFF_NORMED, take minimum
        if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
            top_left = min_loc
        else:
            top_left = max_loc
        bottom_right = (top_left[0] + w, top_left[1] + h)

        cv2.rectangle(img,top_left, bottom_right, 255, 2)

        plt.subplot(121),plt.imshow(res,cmap = 'gray')
        plt.title('Matching Result'), plt.xticks([]), plt.yticks([])
        plt.subplot(122),plt.imshow(img,cmap = 'gray')
        plt.title('Detected Point'), plt.xticks([]), plt.yticks([])
        plt.suptitle(meth)

        plt.show()

main()