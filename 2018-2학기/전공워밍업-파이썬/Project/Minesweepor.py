# 지뢰찾기를 하는 프로그램

import random, time, subprocess
import keyboard # pip install keyboard

MAP = []

FPS = 15

def delay():
    time.sleep(1/FPS)

def main():
    initiate()

    scanMapFile()
    Tile_open(1, 1)

def initiate():
    loadAsset()

    # 콘솔로 플레이하는 지뢰찾기 실행
    runConsoleGame()

def loadAsset():
    global ASSET
    class ASSET:
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

def runConsoleGame():
    subprocess.Popen(['python3', 'Minesweeper.py'])

def scanMapFile(fname='minesweeper.map'):
    # 지뢰찾기 필드를 스캔해서 Map, MapWidth, MapHeight를 업데이트 하는 함수
    global Map, MapWidth, MapHeight
    global ASSET

    f = open(fname, 'r')
    MapWidth = int(f.readline())
    MapHeight = int(f.readline())
    Map = eval(f.read())
    f.close()

def Tile_open(x, y):
    # 메뉴에서 1. 열기 선택
    keyboard.press_and_release('1')
    keyboard.press_and_release('enter')
    delay()

    # X좌표 입력
    keyboard.press_and_release(str(x))
    keyboard.press_and_release('enter')
    delay()

    # Y좌표 입력
    keyboard.press_and_release(str(y))
    keyboard.press_and_release('enter')
    delay()

main()