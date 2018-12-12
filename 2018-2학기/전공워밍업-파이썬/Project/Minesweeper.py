# 지뢰찾기 프로그램 by Hepheir

import random
from colorama import init, Fore, Back, Style

# colorma initialize
init()

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
        if (input("게임을 계속 하시겠습니까? (y/n): ") == 'n'):
            break

def run():
    # 게임 1회 실행하는 함수
    global MINE_GAMEOVER
    
    setMineField()
    Count = 0

    highlightBox = None

    act = None
    x = 0
    y = 0
    while True:
        printMap(highlightBox)

        print("------------ Action ------------")
        print("1. 열기")
        print("2. 깃발 세우기/제거하기")
        print("3. 강조구역 설정")
        print("0. 종료")
        act = int(input(">>> "))

        # 종료
        if act == 0:
            break

        # 강조 할 구역 재설정
        if act == 3:
            h_x1, h_y1, h_x2, h_y2 = [int(k) for k in input("(x1, y1, x2, y2): ").split()]
            highlightBox = (h_x1, h_y1, h_x2, h_y2)
        
        elif act == 1 or act == 2:
            # 작업을 처리할 좌표 입력
            x = int(input("x 좌표 (1~%d): " % MapWidth)) - 1
            y = int(input("y 좌표 (1~%d): " % MapHeight)) - 1

            if act == 1:
                openTile(x, y)

            elif act == 2:
                flagTile(x, y)

        # 잘못된 입력에 대한 예외 처리
        else:
            print("Invalid Input")
            continue

        Tile = Map[x][y]

        # 지뢰가 터졌을 경우, 모든 타일을 열고 필드를 출력해 준 후에 게임 종료.
        if Tile == MINE_GAMEOVER:
            # 처음부터 지뢰가 있는 타일을 골랐을 경우, 지뢰를 터트리지 않고 새로운
            # 맵을 생성함.  
            if Count == 0:
                while Tile != MINE and Tile != MINE_GAMEOVER:
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

def printMap(highlightBox=None):
    # 사용자가 보기 쉽게 필드를 출력하는 함수
    global Map, MapWidth, MapHeight
    global BLANK, MINE, FLAGGED, MINE_FLAGGED, MINE_GAMEOVER
    global SKIN_COVERED, SKIN_OPENED, SKIN_GAMEOVER, SKIN_HIGHLIGHT

    if not highlightBox == None:
        (x1, y1, x2, y2) = highlightBox

    tile_content = ''
    tile_color = None
    tile_backgroundColor = None
    tile_style = None
    
    print("------------ Mine Field ------------")
    for y in range(MapHeight):
        # 보드의 x, y의 칸 번호 안내 표시
        if y == 0:
            print("   ", end='')
            for x in range(MapWidth):
                print(" %-2d" % (x + 1), end='')
            print("")
        print("%2d " % (y + 1), end='')

        for x in range(MapWidth):
            # 만약 하이라이트 구간이 정해져 있으면, 지금 x, y값이 하이라이트 구간 내부인지 확인
            if not highlightBox == None:
                isHighlight = (y1 <= y and y < y2) and (x1 <= x and x < x2)
            else:
                isHighlight = False

            # 열리지 않은 칸 표시
            if Map[x][y] == BLANK or Map[x][y] == MINE:
                tile_content = SKIN_COVERED[0] + '_' + SKIN_COVERED[1]
                
                tile_color = None
                tile_backgroundColor = None

            # 깃발이 꽃혀있는 칸 표시
            elif Map[x][y] == FLAGGED or Map[x][y] == MINE_FLAGGED:
                tile_content = SKIN_COVERED[0] + FLAGGED + SKIN_COVERED[1]
                
                tile_color = Fore.YELLOW
                tile_backgroundColor = None

            # 터트린 지뢰 표시
            elif Map[x][y] == MINE_GAMEOVER:
                tile_content = SKIN_GAMEOVER[0] + MINE + SKIN_GAMEOVER[1]
                
                tile_color = Fore.BLACK
                tile_backgroundColor = Back.RED

            # 열린 칸 - 주변에 지뢰가 없는 빈 칸 표시
            elif Map[x][y] == 0:
                tile_content = SKIN_OPENED[0] + ' ' + SKIN_OPENED[1]
                
                tile_color = Fore.WHITE
                tile_backgroundColor = None

            # 일반 열린 타일은 각 숫자에 해당되는 색상으로 출력
            else:
                tile_num = Map[x][y]
                tile_content = SKIN_OPENED[0] + str(tile_num) + SKIN_OPENED[1]

                if tile_num == 1:
                    tile_color = Fore.BLUE

                elif tile_num == 2:
                    tile_color = Fore.GREEN
                    
                elif tile_num == 3:
                    tile_color = Fore.RED
                    
                elif tile_num == 4:
                    tile_color = Fore.BLUE
                    
                else:
                    tile_color = Fore.CYAN

                tile_backgroundColor = Back.BLACK

            # 하이라이트 구간은 볼드체로 표시
            if isHighlight:
                tile_style = Style.BRIGHT
                tile_color = Fore.MAGENTA
            else:
                tile_style = Style.DIM

            # 기본 색상, 기본 배경
            if tile_color == None:
                tile_color = Fore.RESET

            if tile_backgroundColor == None:
                tile_backgroundColor = Back.RESET

            # 타일을 출력하고, 색상을 다시 원래대로 돌림
            print(
                tile_style +
                tile_color +
                tile_backgroundColor +

                tile_content +

                Fore.RESET +
                Back.RESET +
                Style.RESET_ALL,
            end='')
        print('')

def openAll():
    pass

main()