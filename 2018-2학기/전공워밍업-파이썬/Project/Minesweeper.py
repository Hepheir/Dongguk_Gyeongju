# 지뢰찾기 프로그램 by Hepheir

import random

# Constant
BLANK = '.'
FLAGGED = '!'
MINE = '*'
MINE_FLAGGED = '!*'
MINE_GAMEOVER = '**'

SKIN_COVERED = '[]'
SKIN_OPENED = '  '
SKIN_GAMEOVER = '!!'
SKIN_HIGHLIGHT = '##'

# Global Variables
Map = []
MapWidth = 31
MapHeight = 16
Mines = 79

Count = 0

def main():
    while True:
        run()
        if (input("게임을 계속 하시겠습니까? (y/n)") == 'n'):
            break

def run():
    # 게임 1회 실행하는 함수
    global MINE_GAMEOVER
    
    setMineField()
    Count = 0

    while True:
        printMap()

        x = int(input("x 좌표 (1~%d): " % MapWidth)) - 1
        y = int(input("y 좌표 (1~%d): " % MapHeight)) - 1
        act = int(input("1. 열기\n2. 깃발 세우기/제거하기\n3. 종료\n>>> "))

        if act == 1:
            openTile(x, y)
        elif act == 2:
            flagTile(x, y)
        elif act == 3:
            # 종료
            break

        # 지뢰가 터졌을 경우, 모든 타일을 열고 필드를 출력해 준 후에 게임 종료.
        if Map[x][y] == MINE_GAMEOVER:
            # 처음부터 지뢰가 있는 타일을 골랐을 경우, 지뢰를 터트리지 않고 새로운
            # 맵을 생성함.  
            if Count == 0:
                while Map[x][y] != MINE and Map[x][y] != MINE_GAMEOVER:
                    setMineField()
                openTile(x, y)
            # 게임 오버
            else:
                openAll()
                printMap()
                print("GAME OVER")
                break
        Count += 1

def getEmptyMap():
    # 빈 필드를 생성하는 함수
    global Map, MapWidth, MapHeight
    Map = []
    for i in range(MapWidth):
        Map.append([BLANK] * MapHeight)

def hideMines():
    # 임의의 타일에 지뢰를 심는 함수
    global Map, MapWidth, MapHeight

    x = random.randrange(0, MapWidth)
    y = random.randrange(0, MapHeight)
    # 이미 지뢰가 있으면, 다른 타일에 지뢰를 심음
    if (Map[x][y] == MINE):
        hideMines()
    else:
        Map[x][y] = MINE

def setMineField():
    # 필드를 생성하고 생성한 필드에 지뢰를 심음
    getEmptyMap()
    for i in range(Mines):
        hideMines()

def openTile(x, y):
    # 타일을 여는 함수
    global Map, MapHeight, MapWidth
    global BLANK, MINE, FLAGGED, MINE_FLAGGED, MINE_GAMEOVER

    # 지뢰를 건들면 지뢰가 터짐
    if Map[x][y] == MINE or Map[x][y] == MINE_FLAGGED:
        Map[x][y] = MINE_GAMEOVER
        return

    # 열린 타일에 주변에 있는 지뢰의 수를 표시
    mines = searchMinesAround(x, y)
    print('mines: %d' % mines)
    Map[x][y] = mines

    # 주변에 지뢰가 없으면, 주변의 타일이 함께 열리는 보너스
    if mines == 0:
        for dx in [-1, 0, 1]:
            for dy in [-1 , 0, 1]:
                # 자기 자신 생략
                if dx == 0 and dy == 0:
                    continue

                # 범위 밖으로 가지 않도록 제어
                if x+dx < 0 or y+dy < 0 or x+dx >= MapWidth or y+dy >= MapHeight:
                    continue

                if Map[x+dx][y+dy] == BLANK:
                    openTile(x+dx, y+dy)
      
def searchMinesAround(x, y):
    # 타일 주위에 있는 지뢰를 찾아 그 수를 반환하는 함수
    global Map, MapWidth, MapHeight
    global MINE, MINE_FLAGGED
    
    foundMines = 0
    for dx in [-1, 0, 1]:
        for dy in [-1 , 0, 1]:
            # 자기 자신 생략
            if dx == 0 and dy == 0:
                continue
    
            # 범위 밖으로 가지 않도록 제어
            if x+dx < 0 or y+dy < 0 or x+dx >= MapWidth or y+dy >= MapHeight:
                continue
            
            if Map[x+dx][y+dy] == MINE or Map[x+dx][y+dy] == MINE_FLAGGED:
                foundMines += 1
    return foundMines

def flagTile(x, y):
    # 타일에 깃발을 꽃는 함수
    global Map
    global MINE, MINE_FLAGGED, FLAGGED, BLANK

    # 지뢰가 심어진 칸을 다루는 경우
    if Map[x][y] == MINE:
        Map[x][y] = MINE_FLAGGED
    elif Map[x][y] == MINE_FLAGGED:
        Map[x][y] = MINE

    # 지뢰가 심어지지 않은 칸을 다루는 경우
    elif Map[x][y] == FLAGGED:
        Map[x][y] = BLANK
    else:
        Map[x][y] = FLAGGED
    

class C_COLORS:
    # HEADER = '\033[95m'
    # OKBLUE = '\033[94m'
    # OKGREEN = '\033[92m'
    # WARNING = '\033[93m'
    # FAIL = '\033[91m'
    # ENDC = '\033[0m'
    # BOLD = '\033[1m'
    # UNDERLINE = '\033[4m'
    RED   = "\033[1;31m" #3  
    BLUE  = "\033[1;34m" #1
    CYAN  = "\033[1;36m" #4,5,6,7,8...
    GREEN = "\033[0;32m" #2
    RESET = "\033[0;0m" 
    BOLD    = "\033[;1m"
    REVERSE = "\033[;7m"
    WARNING = '\033[93m'
    FAIL = '\033[91m'

def printMap(highlightBox=None):
    # 사용자가 보기 쉽게 필드를 출력하는 함수
    global Map, MapWidth, MapHeight
    global BLANK, MINE, FLAGGED, MINE_FLAGGED, MINE_GAMEOVER
    global SKIN_COVERED, SKIN_OPENED, SKIN_GAMEOVER, SKIN_HIGHLIGHT

    if not highlightBox == None:
        (x1, y1, x2, y2) = highlightBox
    else:
        isHighlight = False

    charColor = C_COLORS.RESET

    for y in range(MapHeight):
        for x in range(MapWidth):
            if not isHighlight == False:
                isHighlight = (y1 <= y and y < y2) and (x1 <= x and x < x2)

            if Map[x][y] == BLANK or Map[x][y] == MINE:
                tile = SKIN_COVERED[0] + '_' + SKIN_COVERED[1]
                charColor = C_COLORS.RESET

            elif Map[x][y] == FLAGGED or Map[x][y] == MINE_FLAGGED:
                tile = SKIN_COVERED[0] + '!' + SKIN_COVERED[1]
                charColor = C_COLORS.WARNING

            elif Map[x][y] == 0:
                tile = SKIN_OPENED[0] + ' ' + SKIN_OPENED[1]
                charColor = C_COLORS.RESET

            elif Map[x][y] == MINE_GAMEOVER:
                tile = SKIN_GAMEOVER[0] + MINE + SKIN_GAMEOVER[1]
                charColor = C_COLORS.FAIL

            else:
                TileNum = Map[x][y]
                if TileNum == 1:
                    charColor = C_COLORS.BLUE
                elif TileNum == 2:
                    charColor = C_COLORS.GREEN
                elif TileNum == 3:
                    charColor = C_COLORS.RED
                else:
                    charColor = C_COLORS.CYAN

                tile = SKIN_OPENED[0] + str(Map[x][y]) + SKIN_OPENED[1]
    
            if isHighlight:
                print(C_COLORS.BOLD, end='')

            print(charColor, end='')
            print(tile + C_COLORS.RESET, end='')
        print('')

def openAll():
    pass

main()