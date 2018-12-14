import random, time
from colorama import init as colorama_init
from colorama import Fore, Back, Style

FIELD_WIDTH = 31
FIELD_HEIGHT = 16
FIELD_MINES = 79

readInputFromFile = False
writeFieldFile = False
readFileDelayMS = 100

def main():
    init()
    run()

def init():
    colorama_init()

    loadAsset()
    loadSkin()
    loadField()

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

def loadSkin():
    global SKIN
    class Skin:
        covered = '[]'
        opened = '  '
        mine = '!!'
    SKIN = Skin

def loadField():
    global FIELD
    class MineField:
        table = []
        width = 0
        height = 0
        mines = 0
        gameover = False

        def __init__(self, width=0, height=0, mines=0):
            self.resetTable(width, height)
            self.hideMines(mines)        

        def resetTable(self, width, height):
            global ASSET

            self.table = []
            for i in range(width):
                self.table.append([ASSET.blank] * height)

            self.width = width
            self.height = height
            
            self.gameover = False

        def hideMines(self, mines=0):
            global ASSET

            while True:
                if mines == 0:
                    break

                x = random.randrange(0, self.width)
                y = random.randrange(0, self.height)

                if not (self.table[x][y] == ASSET.mine):
                    self.table[x][y] = ASSET.mine
                    mines -= 1

        def open(self, x, y):
            global ASSET

            Tile = self.table[x][y]

            if Tile in [ASSET.flagged, ASSET.mine_flagged]:
                print("깃발을 먼저 해제해주세요.")
                return

            if Tile == ASSET.mine:
                self.table[x][y] = ASSET.mine_gameover
                self._revealMines()
                self.gameover = True
                return

            self._open(x, y)
        
        def flag(self, x, y):
            global ASSET

            Tile = self.table[x][y]

            if Tile == ASSET.blank:
                Tile = ASSET.flagged
            elif Tile == ASSET.mine:
                Tile = ASSET.mine_flagged

            elif Tile == ASSET.flagged:
                Tile = ASSET.blank
            elif Tile == ASSET.mine_flagged:
                Tile = ASSET.mine
            
            else:
                print("깃발을 꽂는데 실패했습니다.")

            self.table[x][y] = Tile

        def _open(self, x, y):
            nearbyMines = 0

            (x1, y1, x2, y2) = self._calibrateBox((x-1, y-1, x+1, y+1))

            for dx in range(x1, x2+1):
                for dy in range(y1, y2+1):
                    if dx == x and dy == y:
                        continue
                    elif self.table[dx][dy] in [ASSET.mine,
                                  ASSET.mine_flagged,
                                  ASSET.mine_gameover,
                                  ASSET.mine_revealed]:
                        nearbyMines += 1
    
            self.table[x][y] = ASSET.open[nearbyMines]

            if not nearbyMines == 0:
                return

            for dx in range(x1, x2+1):
                for dy in range(y1, y2+1):
                    if dx == x and dy == y:
                        continue
                    if self.table[dx][dy] == ASSET.blank:
                        self._open(dx, dy)

        def _calibrateBox(self, box):
            (x1, y1, x2, y2) = box

            width = self.width
            height = self.height

            if x1 < 0:
                x1 = 0
            if y1 < 0:
                y1 = 0
            if x2 >= width:
                x2 = width-1
            if y2 >= height:
                y2 = height-1

            return (x1, y1, x2, y2)

        def _revealMines(self):
            global ASSET
            for x in range(self.width):
                for y in range(self.height):
                    Tile = self.table[x][y]
                    if Tile in [ASSET.mine, ASSET.mine_flagged]:
                        Tile = ASSET.mine_revealed
                    self.table[x][y] = Tile

    ### class MineField의 끝 ###
    FIELD = MineField(FIELD_WIDTH, FIELD_HEIGHT, FIELD_MINES)

def run():
    global FIELD

    highlightBox = None
    menu_code = None

    turns = 0

    while True:
        print("\n\n\n\n")
        print_field(highlightBox)

        print("")
        print("현재 턴 수: %d" % turns)

        if writeFieldFile:
            printFile_field()

        if readInputFromFile:
            menu_code, (x, y), highlightBox = superProcess_input()

            if menu_code == 1:
                FIELD.open(x, y)
                turns += 1

            elif menu_code == 2:
                FIELD.flag(x, y)
                turns += 1

            # DEBUG
            print(str(menu_code))
            print(str((x,y)))
            print(str(highlightBox))

        else:
            menu_code = None
            while menu_code == None:
                menu_code = user_inputMenu()

            if menu_code == 0:
                break

            elif menu_code == 1:
                user_actOpen()
                turns += 1

            elif menu_code == 2:
                user_actFlag()
                turns += 1

            elif menu_code == 3:
                highlightBox = user_setHighlight()

        if FIELD.gameover:
            print_gameover()
            break

def superProcess_input():
    f = None
    updated = False
    content = None

    while not updated:
        f = open('minesweeper.input', 'r')
        content = f.readline()
        f.close()
        
        updated = not content == ''
        time.sleep(readFileDelayMS/1000)

    menu_code = int(content)
    (x, y) = eval(f.readline())
    highlightBox = eval(f.readline())
    
    f = open('minesweeper.input', 'w')
    f.close()

    return [menu_code, (x, y), highlightBox]

def user_inputMenu():
    code = None

    print("-------- Action --------")
    print("1. 열기")
    print("2. 깃발 세우기/제거하기")
    print("3. 강조구역 설정")
    print("0. 종료")
    print("")
    
    print("할 작업을 골라주세요")
    try:
        code = int(input(">>> "))
    except:
        print("-------- Warning --------")
        print("숫자가 아닙니다.")
        print("")
        return None
    else:
        if not (code in [1, 2, 3, 0]):
            print("-------- Warning --------")
            print("잘못된 입력 입니다.")
            print("")
            return None
    return code

def user_actOpen():
    global FIELD
    pos = None

    while pos == None:
        pos = user_inputCoordinate()

    (x, y) = pos
    FIELD.open(x, y)
    
def user_actFlag():
    global FIELD
    pos = None

    while pos == None:
        pos = user_inputCoordinate()

    (x, y) = pos
    FIELD.flag(x, y)

def user_setHighlight():
    global FIELD
    x1 = None
    y1 = None
    x2 = None
    y2 = None

    try:
        x1, y1, x2, y2 = [int(k) for k in input("(x1, y1, x2, y2): ").split()]
    except:
        # 그 외의 경우에는 강조구역 해제
        print("-------- Message --------")
        print("강조구역 해제")
        highlightBox = None
    else:
        print("-------- Message --------")
        print("강조구역 설정")
        highlightBox = FIELD._calibrateBox((
            x1-1, y1-1,
            x2,   y2
        ))

    return highlightBox

def user_inputCoordinate():
    global FIELD

    x = None
    y = None

    print("-------- 좌표 입력 --------")
    print("x y 좌표를 입력 해주세요")
    print("(x : 1~%d / y : 1~%d)" % (FIELD.width, FIELD.height))
    try:
        x, y = [(int(k)-1) for k in input(">>> ").split(' ')]
    except:
        print("-------- Warning --------")
        print("올바르지 못한 입력입니다.")
        print("")
        return None
    else:
        return (x, y) 

def print_field(highlightBox=None):
    # 사용자가 보기 쉽게 필드를 출력하는 함수
    global FIELD, ASSET, SKIN

    if not highlightBox == None:
        (x1, y1, x2, y2) = highlightBox

    def _createTileLayout(content='_', skin=None, fore=Fore.RESET, back=Back.RESET, style=Style.NORMAL, isHighlight=False):
        layout = ''

        if isHighlight:
            layout += Fore.MAGENTA
        else:
            layout += fore

        layout += back
        layout += style

        if skin == None:
            layout += content
        else:
            layout += skin[0] + content + skin[1]

        layout += (Fore.RESET + Back.RESET + Style.RESET_ALL)
        return layout
    
    print("------------ Mine Field ------------")
    line = ''
    for y in range(FIELD.height):
        # 보드의 x, y의 칸 번호 안내 표시 (DIM:어두운 색상으로 표시)
        if y == 0:
            line += _createTileLayout('y\\x', style=Style.DIM)
            for x in range(FIELD.width):
                line += _createTileLayout(' %-2d' % (x + 1), style=Style.DIM)
            print(line)

        line = ''
        line += _createTileLayout('%2d ' % (y + 1), style=Style.DIM)

        for x in range(FIELD.width):
            if (not highlightBox == None):
                isHighlight = (y1 <= y and y < y2) and (x1 <= x and x < x2)
            else:
                isHighlight = False

            Tile = FIELD.table[x][y]

            if Tile in [ASSET.blank, ASSET.mine]:
                line += _createTileLayout('_', SKIN.covered, isHighlight=isHighlight)

            elif Tile in [ASSET.flagged, ASSET.mine_flagged]:
                line += _createTileLayout(ASSET.flagged, SKIN.covered, Fore.YELLOW, isHighlight=isHighlight)

            elif Tile == ASSET.mine_gameover:
                line += _createTileLayout(ASSET.mine, SKIN.mine, Fore.BLACK, Back.RED)

            elif Tile == ASSET.mine_revealed:
                line += _createTileLayout(ASSET.mine, SKIN.mine, Fore.BLACK, Back.YELLOW)

            elif Tile == ASSET.open[0]:
                line += _createTileLayout(' ', SKIN.opened, isHighlight=isHighlight)

            elif Tile == ASSET.open[1]:
                line += _createTileLayout(Tile, SKIN.opened, Fore.BLUE, isHighlight=isHighlight)

            elif Tile == ASSET.open[2]:
                line += _createTileLayout(Tile, SKIN.opened, Fore.GREEN, isHighlight=isHighlight)

            elif Tile == ASSET.open[3]:
                line += _createTileLayout(Tile, SKIN.opened, Fore.RED, isHighlight=isHighlight)

            elif Tile == ASSET.open[4]:
                line += _createTileLayout(Tile, SKIN.opened, Fore.BLUE, isHighlight=isHighlight)

            else:
                line += _createTileLayout(Tile, SKIN.opened, Fore.CYAN, isHighlight=isHighlight)

        print(line)

def print_gameover():
    print_field()

    print(Fore.RED, end='')
    print("------------ GAME OVER ------------", end='')
    print(Fore.RESET)

def printFile_field(fname='minesweeper.field'):
    global FIELD, ASSET
    field = []
    for x in range(FIELD.width):
        field.append([])
        for y in range(FIELD.height):
            Tile = FIELD.table[x][y]
            if Tile == ASSET.mine:
                Tile = ASSET.blank
            elif Tile == ASSET.mine_flagged:
                Tile = ASSET.flagged
            field[x].append(Tile)

    f = open(fname, 'w')
    f.write('%d\n%d\n'%(FIELD.width, FIELD.height) + str(field))
    f.close()

main()