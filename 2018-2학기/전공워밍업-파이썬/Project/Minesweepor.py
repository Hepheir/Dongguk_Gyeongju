# 지뢰찾기를 하는 프로그램

import random
MAP = []

def main():
    x = 0
    y = 0

    with PROC as p:
        for line in p.stdout:
            print(line, end='')
def initiate():
    global BLANK, MINE, FLAGGED, MINE_FLAGGED, MINE_REVEALED, MINE_GAMEOVER

    BLANK = '.'
    FLAGGED = '!'
    MINE = '*'
    MINE_FLAGGED = '!*'
    MINE_GAMEOVER = '**'
    MINE_REVEALED = '_*'

def scanMapFile(fname='minesweeper.map'):
    # 지뢰가 모두 숨겨진 맵을 파일로 출력
    global Map, MapWidth, MapHeight
    global BLANK, MINE, FLAGGED, MINE_FLAGGED

    f = open(fname, 'r')
    f.read()
    f.close()

main()