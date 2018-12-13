# 지뢰찾기 프로그램 by Hepheir

import random
from colorama import init, Fore, Back, Style

exportAsFile = True

# colorma initialize
init()

# Constant
BLANK = '.'
FLAGGED = '!'
MINE = '*'
MINE_FLAGGED = '!*'
MINE_GAMEOVER = '**'
MINE_REVEALED = '_*'

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
    run()

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
        print("현재 턴 수: %d\n" % Count)
        print("1. 열기")
        print("2. 깃발 세우기/제거하기")
        print("3. 강조구역 설정")
        print("0. 종료")
        print("")
        
        print("할 작업을 골라주세요")
        act = int(input(">>> "))
        
        # 잘못된 입력에 대한 예외처리 1
        try:
        except:
            print("Invalid Input")
            continue

        # 종료
        if act == 0:
            break

        # 강조 할 구역 재설정
        if act == 3:
            try:
                h_x1, h_y1, h_x2, h_y2 = [int(k) for k in input("(x1, y1, x2, y2): ").split()]
                highlightBox = (
                    h_x1 - 1, h_y1 - 1,
                    h_x2, h_y2
                )
            except:
                print("강조구역 해제")
                highlightBox = None
            
            # Count가 +1 되지 않게 continue 시킴
            continue
        
        # 좌표가 필요한 작업
        elif act == 1 or act == 2:
            print("")
            print("좌표를 차례대로 입력 해주세요")
            x = int(input("x 좌표 (1~%d): " % MapWidth)) - 1
            y = int(input("y 좌표 (1~%d): " % MapHeight)) - 1

            if act == 1:
                openTile(x, y)

            elif act == 2:
                flagTile(x, y)

        # 잘못된 입력에 대한 예외처리 2
        else:
            print("Invalid Number")
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
                revealMines() # 숨겨져 있던 지뢰들은 표시해주고 끝냄
                printMap()
                print(Fore.RED, end='')
                print("------------ GAME OVER ------------", end='')
                print(Fore.RESET)
                break
        Count += 1

def getEmptyMap():
    # 빈 필드를 생성하는 함수
    global MapWidth, MapHeight
    _Map = []
    for i in range(MapWidth):
        _Map.append([BLANK] * MapHeight)
    return _Map

def hideMines(Map):
    # 임의의 타일에 지뢰를 심는 함수
    global MapWidth, MapHeight

    x = random.randrange(0, MapWidth)
    y = random.randrange(0, MapHeight)
    # 이미 지뢰가 있으면, 다른 타일에 지뢰를 심음
    if (Map[x][y] == MINE):
        Map = hideMines(Map)
    else:
        Map[x][y] = MINE
    return Map

def setMineField():
    # 필드를 생성하고 생성한 필드에 지뢰를 심음
    global Map
    Map = getEmptyMap()
    for i in range(Mines):
        Map = hideMines(Map)

def openTile(x, y):
    # 타일을 여는 함수
    global Map, MapHeight, MapWidth
    global BLANK, MINE, FLAGGED, MINE_FLAGGED, MINE_GAMEOVER

    # 깃발이 꽃혀있는 곳은 열지 못함
    if Map[x][y] == FLAGGED or Map[x][y] == MINE_FLAGGED:
        print("Can not open the flagged place.")
        return

    # 지뢰를 건들면 지뢰가 터짐
    if Map[x][y] == MINE:
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

    Tile = Map[x][y]

    # 지뢰가 심어진 칸을 다루는 경우
    if Tile == MINE:
        Map[x][y] = MINE_FLAGGED
    elif Tile == MINE_FLAGGED:
        Map[x][y] = MINE

    # 지뢰가 심어지지 않은 칸을 다루는 경우
    elif Tile == FLAGGED:
        Map[x][y] = BLANK
    elif Tile == BLANK:
        Map[x][y] = FLAGGED
    
    else:
        print("Could not place a flag.")

def printMap(highlightBox=None):
    # 사용자가 보기 쉽게 필드를 출력하는 함수
    global Map, MapWidth, MapHeight
    global BLANK, MINE, FLAGGED, MINE_FLAGGED, MINE_REVEALED, MINE_GAMEOVER
    global SKIN_COVERED, SKIN_OPENED, SKIN_GAMEOVER, SKIN_HIGHLIGHT

    if not highlightBox == None:
        (x1, y1, x2, y2) = highlightBox

    tile_content = ''
    tile_color = None
    tile_backgroundColor = None
    tile_style = None
    
    print("------------ Mine Field ------------")
    for y in range(MapHeight):
        # 보드의 x, y의 칸 번호 안내 표시 (DIM:어두운 색상으로 표시)
        if y == 0:
            print(Style.DIM, end='')
            print("y\\x", end='')
            for x in range(MapWidth):
                print(" %-2d" % (x + 1), end='')
            print(Style.RESET_ALL)
    
        print(Style.DIM, end='')
        print("%2d " % (y + 1), end=Style.RESET_ALL)

        for x in range(MapWidth):
            # 만약 하이라이트 구간이 정해져 있으면, 지금 x, y값이 하이라이트 구간 내부인지 확인
            if not highlightBox == None:
                isHighlight = (y1 <= y and y < y2) and (x1 <= x and x < x2)
            else:
                isHighlight = False

            # 열리지 않은 칸 표시
            if Map[x][y] == BLANK or Map[x][y] == MINE:
                tile_content = ApplyTileSkin('_', SKIN_COVERED)
                tile_color = None
                tile_backgroundColor = None

            # 깃발이 꽃혀있는 칸 표시
            elif Map[x][y] == FLAGGED or Map[x][y] == MINE_FLAGGED:
                tile_content = ApplyTileSkin(FLAGGED, SKIN_COVERED)
                tile_color = Fore.YELLOW
                tile_backgroundColor = None

            # 터트린 지뢰 표시
            elif Map[x][y] == MINE_GAMEOVER:
                tile_content = ApplyTileSkin(MINE, SKIN_GAMEOVER)
                
                tile_color = Fore.BLACK
                tile_backgroundColor = Back.RED

            # 게임 오버시 숨겨진 지뢰 표시
            elif Map[x][y] == MINE_REVEALED:
                tile_content = ApplyTileSkin(MINE, SKIN_GAMEOVER)
                tile_color = Fore.BLACK
                tile_backgroundColor = Back.YELLOW

            # 열린 칸 - 주변에 지뢰가 없는 빈 칸 표시
            elif Map[x][y] == 0:
                tile_content = ApplyTileSkin(' ', SKIN_OPENED)
                tile_color = None
                tile_backgroundColor = None

            # 일반 열린 타일은 각 숫자에 해당되는 색상으로 출력
            else:
                tile_num = Map[x][y]
                
                tile_content = ApplyTileSkin(str(tile_num), SKIN_OPENED)
                tile_backgroundColor = None

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

            # 하이라이트 구간은 볼드체로 표시
            if isHighlight:
                tile_color = Fore.MAGENTA
                tile_style = Style.BRIGHT
            else:
                tile_style = None

            # 기본 색상, 기본 배경, 기본 스타일
            if tile_color == None:
                tile_color = Fore.RESET
            if tile_backgroundColor == None:
                tile_backgroundColor = Back.RESET
            if tile_style == None:
                tile_style = Style.NORMAL

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
    
    if exportAsFile:
        printMapFile()

def ApplyTileSkin(Tile, Skin):
    return Skin[0] + Tile + Skin[1]

def printMapFile(fname='minesweeper.map'):
    # 지뢰가 모두 숨겨진 맵을 파일로 출력
    global Map, MapWidth, MapHeight
    global BLANK, MINE, FLAGGED, MINE_FLAGGED

    _Map = getEmptyMap()
    for x in range(MapWidth):
        for y in range(MapHeight):
            Tile = Map[x][y]

            if Tile == MINE:
                Tile = BLANK

            elif Tile == MINE_FLAGGED:
                Tile = FLAGGED
            _Map[x][y] = Tile

    f = open(fname, 'w')
    f.write('%d\n%d\n'%(MapWidth, MapHeight) + str(_Map))
    f.close()

def revealMines():
    for x in range(MapWidth):
        for y in range(MapHeight):
            if Map[x][y] == MINE or Map[x][y] == MINE_FLAGGED:
                Map[x][y] = MINE_REVEALED

main()