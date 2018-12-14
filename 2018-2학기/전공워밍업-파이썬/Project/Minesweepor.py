# 지뢰찾기를 하는 프로그램

import random, time, subprocess
import keyboard # pip install keyboard

FPS = 2

MAP = []

curX = 0
curY = 0

def main():
    initiate()

    # MapFile이 업데이트 되면 동작 실행. 폴링 방식
    while True:
        if scanMapFile:
            break
        delay()

    finish()
    print("Fined.")

def initiate():
    loadAsset()

    # 콘솔로 플레이하는 지뢰찾기 실행
    runConsoleGame()
    delay(2)

def finish():
    closeConsoleGame()

#######################################
#   서포트
#######################################

def calibrateBox(box):
    (x1, y1, x2, y2) = box
    if x1 < 0:
        x1 = 0
    if y1 < 0:
        y1 = 0
    if x2 >= MapWidth:
        x2 = MapWidth-1
    if y2 >= MapHeight:
        y2 = MapHeight-1
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

def loadAsset():
    global ASSET
    class Asset:
        BLANK = '.'
        FLAGGED = '!'
        MINE = '*'
        MINE_FLAGGED = '!*'
        MINE_GAMEOVER = '**'
        MINE_REVEALED = '_*'

        OPEN_0 = 0
        OPEN_1 = 1
        OPEN_2 = 2
        OPEN_3 = 3
        OPEN_4 = 4
        OPEN_5 = 5
        OPEN_6 = 6
        OPEN_7 = 7
        OPEN_8 = 8
    ASSET = Asset

def scanMapFile(fname='minesweeper.map'):
    # 지뢰찾기 필드를 스캔해서 Map, MapWidth, MapHeight를 업데이트 하는 함수
    global Map, MapWidth, MapHeight

    f = open(fname, 'r')
    
    firstLine = f.readline()
    if firstLine == '':
        return False

    MapWidth = int(firstLine)
    MapHeight = int(f.readline())
    Map = eval(f.read())
    f.close()

    # 파일을 읽고 났으면 지움
    f = open(fname, 'w')
    f.close()

    return True

def runConsoleGame():
    global Minesweeper
    Minesweeper = subprocess.Popen(['python',
                                    'Minesweeper.py'],
                                    stdin = subprocess.PIPE,
                                    stdout = subprocess.PIPE,
                                    stderr = subprocess.PIPE,
                                    universal_newlines=True,
                                    bufsize=0)

def closeConsoleGame():
    print('0')

#######################################
#   외부 프로세스에 입출력을 하기 위한 함수들
#######################################

def Tile_select(x, y):
    global Minesweeper
    write = Minesweeper.stdin.write
    write(str(x+1)+'\n')
    write(str(y+1)+'\n')
    pass

    keyboard.press_and_release(str(x+1))
    keyboard.press_and_release('enter')
    delay()

    keyboard.press_and_release(str(y+1))
    keyboard.press_and_release('enter')
    delay()

def Tile_open(x, y):
    keyboard.press_and_release('1')
    keyboard.press_and_release('enter')
    delay()

    Tile_select(x, y)

def Tile_flag(x, y):
    keyboard.press_and_release('2')
    keyboard.press_and_release('enter')
    delay()

    Tile_select(x, y)

def Tile_highlight(highlightBox):
    (x1, y1, x2, y2) = highlightBox

    keyboard.press_and_release('3')
    keyboard.press_and_release('enter')
    delay()
    keyboard.write('%d %d %d %d' % (x1, y1, x2, y2))
    keyboard.press_and_release('enter')
    delay()

def delay(exct=1):
	time.sleep(1/FPS * exct)

main()