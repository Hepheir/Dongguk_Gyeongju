# 지뢰찾기를 하는 프로그램

import random, time, subprocess

readFileDelayMS = 100

def main():
    init()

    runConsoleGame()

def init():
    loadAsset()
    loadField()
    loadOutput()

def loadAsset():
    global ASSET
    class Asset:
        blank = '.'
        flagged = '!'

        mine = '*'
        mine_flagged = '!*'
        mine_gameover = '**'
        mine_revealed = '_*'

        open = [
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8']
    ASSET = Asset

def loadField():
    global FIELD
    class Field():
        table = []
        width = 0
        height = 0
    FIELD = Field

def loadOutput():
    global OUTPUT
    class Output():
        menu_code = 0
        x = 0
        y = 0
        box = (0, 0, 0, 0)
    OUTPUT = Output

#######################################
#   서포트
#######################################

def calibrateBox(box):
    global FIELD
    (x1, y1, x2, y2) = box
    if x1 < 0:
        x1 = 0
    if y1 < 0:
        y1 = 0
    if x2 >= FIELD.width:
        x2 = FIELD.width-1
    if y2 >= FIELD.height:
        y2 = FIELD.height-1
    return (x1, y1, x2, y2)
    
#######################################
#   논리
#######################################

def frame_openConfident(x, y):
    global ASSET
    flaggedMines = 0

    Tile_highlight(calibrateBox((x, y, x, y)))

    view = [
        '111',
        '101',
        '111']
    Tile = Map[x][y]
    if (Tile == ASSET.OPEN_0):
        pass


    Tile_highlight(calibrateBox((x-1, y-1, x+1, y+1)))
    
    pass

#######################################
#   외부 프로세스에 접근하기 위한 함수들
#######################################

def runConsoleGame():
    global SUB_PROC
    SUB_PROC = subprocess.Popen(['python', 'Minesweeper.py'])

def closeConsoleGame():
    SUB_PROC.wait()

#######################################
#   외부 프로세스에 입출력을 하기 위한 함수들
#######################################

def readFile_input(fname='minesweeper.in'):
    global FIELD
    f = None
    updated = False
    content = None

    while not updated:
        f = open(fname, 'r')
        content = f.readline()
        f.close()
        
        updated = not content == ''
        time.sleep(readFileDelayMS/1000)

    FIELD.width = int(content)
    FIELD.height = int(f.readline())
    FIELD.table = eval(f.readline())
    
    f = open(fname, 'w')
    f.close()

def writeFile_ouput(fname='minesweeper.out'):
    global OUTPUT
    f = open(fname, 'w')
    f.writelines([str(line) for line in [
        OUTPUT.menu_code,
        (OUTPUT.x, OUTPUT.y),
        OUTPUT.box
    ]])
    f.close()

main()