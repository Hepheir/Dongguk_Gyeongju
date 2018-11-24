# Simple Memory Puzzle Game
# by Younggak Shin, 2018
# for final term project of Engineering Design class @ Kyung Hee Univ., Korea

import random, time, pygame, sys
from pygame.locals import *

FPS = 25
WINDOWWIDTH = 700
WINDOWHEIGHT = 500
BOXSIZE = 20
CARDWIDTH = 70
CARDHEIGHT = 110
BOARDWIDTH = 28
BOARDHEIGHT = 20
BLANK = '.'
OPENINT = 1

MOVEFREQ = 0.1

XMARGIN = int((WINDOWWIDTH - BOARDWIDTH * BOXSIZE) / 2)
TOPMARGIN = WINDOWHEIGHT - (BOARDHEIGHT * BOXSIZE) - 5

#               R    G    B
WHITE       = (255, 255, 255)
GRAY        = (185, 185, 185)
DARKGRAY    = (200, 200, 200)
BLACK       = ( 20,  20,  20)
RED         = (155,   0,   0)
LIGHTRED    = (175,  20,  20)
ORANGE      = (255, 153,   0)
LIGHTORANGE = (255, 173,  20)
YELLOW      = (155, 155,   0)
LIGHTYELLOW = (175, 175,  20)
GREEN       = (  0, 155,   0)
LIGHTGREEN  = ( 20, 175,  20)
BLUE        = (  0,   0, 155)
LIGHTBLUE   = ( 20,  20, 175)
BLUEGREEN   = (000, 102, 102)
LIGHTBLUEGREEN = (  20, 122, 122)
PURPLE      = (153,   0, 153)
LIGHTPURPLE = (173,  20, 173)
PEACH       = (255, 153, 153)
LIGHTPEACH  = (255, 173, 173)

BORDERCOLOR = WHITE
BGCOLOR = BLACK
TEXTCOLOR = WHITE
TEXTSHADOWCOLOR = GRAY
LETTERIMGCOLOR = BLACK
COLORS      = (GRAY, RED, ORANGE, YELLOW, GREEN, BLUE, BLUEGREEN, PURPLE, PEACH)
LIGHTCOLORS = (GRAY, LIGHTRED, LIGHTORANGE, LIGHTYELLOW, LIGHTGREEN, LIGHTBLUE, LIGHTBLUEGREEN, LIGHTPURPLE, LIGHTPEACH)

TEMPLATEWIDTH = 7
TEMPLATEHEIGHT = 5

WORDBANK    = ('CAT', 'BAT', 'DOG', 'BIRD', 'RHCP', 'OASIS', 'BLUR', 'MGMT', 'KOR', 'US', 'GB', 'JPN')

CURSOR_TEMPLATE = [ 'OOOOOOO',
                    'O.....O',
                    'O.....O',
                    'O.....O',
                    'OOOOOOO']


def main():
    global FPSCLOCK, DISPLAYSURF,SMALLFONT, BASICFONT, BIGFONT
    pygame.init()
    FPSCLOCK = pygame.time.Clock()
    DISPLAYSURF = pygame.display.set_mode((WINDOWWIDTH, WINDOWHEIGHT))
    SMALLFONT = pygame.font.Font('freesansbold.ttf', 12)
    BASICFONT = pygame.font.Font('freesansbold.ttf', 18)
    BIGFONT = pygame.font.Font('freesansbold.ttf', 70)
    pygame.display.set_caption('Memory Puzzle @ KHU')

    showTextScreen('Memory Puzzle')
    while True: # game loop
        level = 0
        runGame(level) # the game is initiated here
        showTextScreen('Game Over')


def runGame(level):
    print('flash memory game has begun..!')
    # setup variables for the start of the game and start a game
    board = getBlankBoard()
    life = 20  
    flipping = 0
    lastMoveTime = time.time()
    lastFlippingTime = time.time()

    # Initial key status
    pauseOn = False
    movingUp = False
    movingDown = False
    movingLeft = False
    movingRight = False
    clicking = False

    boardInfo = getCards() # get a set of cards
    cursor = getCursor() # bring a cursor on the screen
    while True: # game loop
        if life == 0:
            showTextScreen('Game Over')
            #terminate()
            return # game over

        checkForQuit()

        # key handling
        for event in pygame.event.get(): # event handling loop
            if event.type == KEYUP:
                if event.key == K_c:
                    # pause the game
                    print('game paused.')
                    DISPLAYSURF.fill(BGCOLOR)
                    infoScreen()
                    lastMoveTime = time.time()
                elif (event.key == K_LEFT or event.key == K_a):
                    movingLeft = False
                elif (event.key == K_RIGHT or event.key == K_d):
                    movingRight = False
                elif (event.key == K_UP or event.key == K_w):
                    movingUp = False
                elif (event.key == K_DOWN or event.key == K_s):
                    movingDown = False
                elif event.key == K_SPACE:
                    clicking = False

            elif event.type == KEYDOWN:
                # update cursor position
                if (event.key == K_LEFT or event.key == K_a) and isValidPosition(board, cursor, adjX=-1):
                    movingLeft = True
                    movingRight = False
                    lastMoveTime = time.time()
                elif (event.key == K_RIGHT or event.key == K_d) and isValidPosition(board, cursor, adjX=1):
                    movingRight = True
                    movingLeft = False
                    lastMoveTime = time.time()
                elif (event.key == K_UP or event.key == K_w) and isValidPosition(board, cursor, adjY=-1):
                    movingUp = True
                    movingDown = False
                    lastMoveTime = time.time()
                elif (event.key == K_DOWN or event.key == K_s) and isValidPosition(board, cursor, adjY=1):
                    movingDown = True
                    movingUp = False
                    lastMoveTime = time.time()
                # update flipping status
                if event.key == K_SPACE:
                    if flipping < 2:
                        clicking = True
                        flipping = flipping+1
                    else:
                        clicking = True
        # pause check
        if pauseOn:
            print('game paused.')
            DISPLAYSURF.fill(BGCOLOR)
            infoScreen()
            pauseOn = False
        
        # flipping frezzer
        if flipping == 2:
            lastFlippingTime = time.time()
        if flipping == 3:
            tstamp = time.time()
            if (tstamp - lastFlippingTime) > OPENINT:
                flipping = 0
        
        # Moving cursor & flipping
        if time.time() - lastMoveTime > MOVEFREQ:
            if movingLeft and isValidPosition(board, cursor, adjX=-1):
                cursor['x'] -= 7
            elif movingRight and isValidPosition(board, cursor, adjX=1):
                cursor['x'] += 7
            elif movingUp and isValidPosition(board, cursor,adjY=-1):
                cursor['y'] -= 5
            elif movingDown and isValidPosition(board, cursor, adjY=1):
                cursor['y'] += 5
            lastMoveTime = time.time()
        
        # locate the cursor
        xpos = cursor['x']/7
        ypos = cursor['y']/5
        xpos = int(xpos)
        ypos = int(ypos)

        # flip cards, check if they are pair, update status, and take a life
        if clicking and flipping < 3:
            if boardInfo[ypos][xpos]['open'] == 1:
                flipping = flipping - 1
            else:
                boardInfo = flippingCard(xpos,ypos,boardInfo)
        lifetaker, boardInfo = closingManager(lastFlippingTime,flipping,xpos,ypos,boardInfo)
        life = life - lifetaker
        clicking = False

        # flipping control
        if flipping == 2:
            if boardInfo[ypos][xpos]['found'] == 1:
                flipping = 0
            else:
                flipping = 3
                    

        # drawing everything on the screen
        DISPLAYSURF.fill(BGCOLOR)
        drawBoard(board)
        drawStatus(life, level)
        drawCursor(cursor) # drawPiece
        drawCard(boardInfo)

        pygame.display.update()
        FPSCLOCK.tick(FPS)

        # check for clear
        if checkForClear(boardInfo) == True:
            level = level+1
            runGame(level)


def makeTextObjs(text, font, color):
    surf = font.render(text, True, color)
    return surf, surf.get_rect()


def terminate():
    pygame.quit()
    sys.exit()


def checkForKeyPress():
    # Go through event queue looking for a KEYUP event.
    # Grab KEYDOWN events to remove them from the event queue.
    checkForQuit()

    for event in pygame.event.get([KEYDOWN, KEYUP]):
        if event.type == KEYDOWN:
            continue
        return event.key
    return None


def showTextScreen(text):
    # This function displays large text in the
    # center of the screen until a key is pressed.
    # Draw the text drop shadow
    titleSurf, titleRect = makeTextObjs(text, BIGFONT, TEXTSHADOWCOLOR)
    titleRect.center = (int(WINDOWWIDTH / 2), int(WINDOWHEIGHT / 2))
    DISPLAYSURF.blit(titleSurf, titleRect)

    # Draw the text
    titleSurf, titleRect = makeTextObjs(text, BIGFONT, TEXTCOLOR)
    titleRect.center = (int(WINDOWWIDTH / 2) - 3, int(WINDOWHEIGHT / 2) - 3)
    DISPLAYSURF.blit(titleSurf, titleRect)

    # Draw the additional "Press a key to play." text.
    pressKeySurf, pressKeyRect = makeTextObjs('Press a key to play.', BASICFONT, TEXTCOLOR)
    pressKeyRect.center = (int(WINDOWWIDTH / 2), int(WINDOWHEIGHT / 2) + 100)
    DISPLAYSURF.blit(pressKeySurf, pressKeyRect)

    while checkForKeyPress() == None:
        pygame.display.update()
        FPSCLOCK.tick()


def infoScreen():
    # center of the screen until a key is pressed.
    text = [[],[],[],[]]
    spacing = 40
    ####################################################################
    # task 4. game info                                                #
    ####################################################################
    text[0] = "[Memory puzzle game finished code]"
    text[1] = "coded by Jeong Gwang Eun"
    text[2] = "please enjoy the game..!"
    text[3] = "2018 Engineering Design Class @ KHU, Korea"
    ####################################################################
    for i in range(0,4):
        titleSurf, titleRect = makeTextObjs(text[i] , BASICFONT, TEXTSHADOWCOLOR)
        titleRect.center = (int(WINDOWWIDTH / 2), int(WINDOWHEIGHT / 2 -100+spacing*i))
        DISPLAYSURF.blit(titleSurf, titleRect)
    pressKeySurf, pressKeyRect = makeTextObjs('Press a key to resume.', BASICFONT, TEXTCOLOR)
    pressKeyRect.center = (int(WINDOWWIDTH / 2), int(WINDOWHEIGHT / 2) + 100)
    DISPLAYSURF.blit(pressKeySurf, pressKeyRect)

    while checkForKeyPress() == None:
        pygame.display.update()
        FPSCLOCK.tick()


def lettering(text,ypos,xpos):
    # This function displays the given text at given position
    # Draw the text
    text = str(text)
    titleSurf, titleRect = makeTextObjs(text, SMALLFONT, WHITE)
    titleRect.center = (xpos + 35  +  XMARGIN + int(CARDWIDTH / 2), ypos + TOPMARGIN + int(CARDHEIGHT / 2) - 3)
    DISPLAYSURF.blit(titleSurf, titleRect)


def checkForClear(boardInfo):
    # This function checks if the game is cleared.
    # If the game is cleared, return clear 'True'
    clear = False
    state = isGameCleared(boardInfo)
    if state == True:
        clear = True
    return clear


def checkForQuit():
    for event in pygame.event.get(QUIT): # get all the QUIT events
        terminate() # terminate if any  QUIT events are present
    for event in pygame.event.get(KEYUP): # get all the KEYUP events
        if event.key == K_ESCAPE:
            terminate() # terminate if the KEYUP event was for the Esc key
        pygame.event.post(event) # put the other KEYUP event objects back


def getCards():
    # This function is called when the new game starts.
    # Prepare a set of cards to play
    boardInfo = [[{},{},{},{}],[{},{},{},{}],[{},{},{},{}],[{},{},{},{}]]
    picked = getWords() # pick 8 words to play
    boardInfo = shuffleCards(picked,boardInfo) # shuffle cards
    boardInfo = getColors(picked,boardInfo) # color cards
    return boardInfo


def getWords():
    # This function picks 8 words to play.
    # It outputs 8 array index numbers of chosen words in WORDBANK.
    size = len(WORDBANK) # size: the number of words in WORDBANK. You can use it.

    #####################################################################
    # task 1. randomly pick 8 words                                     #
    #####################################################################
    picked = random.sample(range(0,size),8)
    #####################################################################
    return picked


def shuffleCards(picked,boardInfo):
    # This function shuffles the cards to randomly arrange them on the board.
    shuffled = [-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16]
    for i in range(0,8):
        shuffled[i*2] = picked[i]
        shuffled[i*2+1] = picked[i]
    check = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(0,4):
        for j in range(0,4):
            while True:
                tmp = random.randint(0,15)
                if check[tmp] == 0:
                    # The dictionary form of each elements in boardInfo is defined here.
                    boardInfo[i][j] = {'word':shuffled[tmp], 'color':0, 'open':0, 'found':0, 'ftime':0}
                    check[tmp] = 1
                    break
    return boardInfo


def getColors(picked,boardInfo):
    # This function assigns colors to cards

    #####################################################################
    # task 2. randomly color cards                                      #
    #####################################################################

    # Randomly assigns color codes for each pair of the words.
    pickedColor = random.sample(range(0, len(COLORS)), 8)
    # Memorize an word-code to assign same color per pair of the words.
    pickedWord = [-1, -2, -3, -4, -5, -6, -7, -8]

    for i in range(0,4):
        for j in range(0,4):
            for k in range(0,8):
                # if the word have not got a color yet, assign a color.
                if pickedWord[k] < 0:
                    pickedWord[k] = boardInfo[i][j]['word']
                    boardInfo[i][j]['color'] = pickedColor[k]
                    break

                # if the other pair-of-the-word has got a color assigned,
                # get the same color with that. 
                if pickedWord[k] == boardInfo[i][j]['word']:
                    boardInfo[i][j]['color'] = pickedColor[k]
                    break

    #####################################################################
    return boardInfo


def getCursor():
    newCursor = {'x': 0,
                'y': 0, # start it above the board (i.e. less than 0)
                }
    return newCursor


def getBlankBoard():
    # create and return a new blank board data structure
    board = []
    for i in range(BOARDWIDTH):
        board.append([BLANK] * BOARDHEIGHT)
    return board


def isGameCleared(boardInfo):
    clear = False
    counter = 0
    for i in range (0,4):
        for j in range (0,4):
            if boardInfo[i][j]['found'] == 1:
                counter = counter +1
    if counter == 16:
        clear = True
    return clear


def isOnBoard(x, y):
    return x >= 0 and x < BOARDWIDTH and y >= 0 and y < BOARDHEIGHT


def isValidPosition(board, cursor, adjX=0, adjY=0):
    # Return True if the piece is within the board and not colliding
    for x in range(TEMPLATEWIDTH):
        for y in range(TEMPLATEHEIGHT):
            if not isOnBoard(x + cursor['x'] + adjX, y + cursor['y'] + adjY):
                return False
    return True


def convertToPixelCoords(boxx, boxy):
    # Convert the given xy coordinates of the board to xy
    # coordinates of the location on the screen.
    return (XMARGIN + (boxx * BOXSIZE)), (TOPMARGIN + (boxy * BOXSIZE))


def flippingCard(xpos,ypos,boardInfo):
    boardInfo[ypos][xpos]['open'] = 1
    return boardInfo


def closingManager(lastFlippingTime,flipping,xpos,ypos,boardInfo):
    lifetaker = 0
    if flipping == 2:
        lifetaker, boardInfo = pairCheck(xpos,ypos,boardInfo)
        for i in range(0,4):
            for j in range(0,4):
                if boardInfo[i][j]['open'] == 1:
                    boardInfo[i][j]['ftime'] = lastFlippingTime
        # if flipped cards are not a pair: close after 2 secs
        # else if flipped card are a pair: stay open
    if flipping == 0:
        for i in range(0,4):
            for j in range(0,4):
                if boardInfo[i][j]['open'] == 1:
                    if boardInfo[i][j]['found'] == 0:
                        boardInfo[i][j]['open'] = 0
    return lifetaker, boardInfo


def pairCheck(xpos,ypos,boardInfo):
    # This function checks if currently flipped cards are pair.
    # If it is, set 'found' values of flipped cards to '1'.
    # If it is not, set 'lifetaker' value to '1' to take a life.

    #####################################################################
    # task 3. check flipped cards are pair                              #
    #####################################################################
    
    lifetaker = 1

    for i in range(0,4):
        for j in range(0,4):
            if boardInfo[i][j]['open'] == 1:
                # checks if the cards share the same word.
                sameWord = boardInfo[i][j]['word'] == boardInfo[ypos][xpos]['word']
                # checks if the chosen position i, j is same with ypos, xpos.  
                samePos = i == ypos and j == xpos
            
                if sameWord and not samePos:
                    # if a pair of word is found, disable lifetaker.
                    boardInfo[ypos][xpos]['found'] = 1
                    boardInfo[i][j]['found'] = 1
                    lifetaker = 0

                    # stop doing unnecessary comparison
                    return lifetaker, boardInfo
    
    #####################################################################
    return lifetaker, boardInfo

 
def drawBox(boxx, boxy, color, pixelx=None, pixely=None):
    # draw a single box (each tetromino piece has four boxes)
    # at xy coordinates on the board. Or, if pixelx & pixely
    # are specified, draw to the pixel coordinates stored in
    # pixelx & pixely (this is used for the "Next" piece).
    if color == BLANK:
        return
    if pixelx == None and pixely == None:
        pixelx, pixely = convertToPixelCoords(boxx, boxy)
    pygame.draw.rect(DISPLAYSURF, COLORS[color], (pixelx + 1, pixely + 1, BOXSIZE - 1, BOXSIZE - 1))
    pygame.draw.rect(DISPLAYSURF, LIGHTCOLORS[color], (pixelx + 1, pixely + 1, BOXSIZE - 4, BOXSIZE - 4))


def drawCard(boardInfo):
    # This function draws cards
    for i in range(0,4):
        for j in range(0,4):
            pixelx = j*140
            pixely = i*100
            if boardInfo[i][j]['open'] == 0:
                pygame.draw.rect(DISPLAYSURF, DARKGRAY, (XMARGIN + pixelx+15, TOPMARGIN + pixely+15, CARDHEIGHT, CARDWIDTH))
            else:
                if boardInfo[i][j]['found'] == 0:
                    pygame.draw.rect(DISPLAYSURF, COLORS[boardInfo[i][j]['color']], (XMARGIN + pixelx+15, TOPMARGIN + pixely+15, CARDHEIGHT, CARDWIDTH))
                else:
                    pygame.draw.rect(DISPLAYSURF, LIGHTCOLORS[boardInfo[i][j]['color']], (XMARGIN + pixelx+15, TOPMARGIN + pixely+15, CARDHEIGHT, CARDWIDTH))
                lettering(WORDBANK[boardInfo[i][j]['word']],pixely,pixelx)


def drawBoard(board):
    # draw the border around the board
    pygame.draw.rect(DISPLAYSURF, BORDERCOLOR, (XMARGIN - 3, TOPMARGIN - 7, (BOARDWIDTH * BOXSIZE) + 8, (BOARDHEIGHT * BOXSIZE) + 8), 5)

    # fill the background of the board
    pygame.draw.rect(DISPLAYSURF, BGCOLOR, (XMARGIN, TOPMARGIN, BOXSIZE * BOARDWIDTH, BOXSIZE * BOARDHEIGHT))
    # draw the individual boxes on the board
    for x in range(BOARDWIDTH):
        for y in range(BOARDHEIGHT):
            drawBox(x, y, board[x][y])


def drawStatus(life, level):
    # draw the score text
    scoreSurf = BASICFONT.render('Life: %s' % life, True, TEXTCOLOR)
    scoreRect = scoreSurf.get_rect()
    scoreRect.topleft = (WINDOWWIDTH - 137, 20)
    DISPLAYSURF.blit(scoreSurf, scoreRect)

    # draw the level text
    levelSurf = BASICFONT.render('# of game cleared: %s' % level, True, TEXTCOLOR)
    levelRect = levelSurf.get_rect()
    levelRect.topleft = (WINDOWWIDTH - 250, 50)
    DISPLAYSURF.blit(levelSurf, levelRect)

    # draw the game info. page text
    levelSurf = BASICFONT.render('game info: press (c)', True, GRAY)
    levelRect = levelSurf.get_rect()
    levelRect.topleft = (70, 35)
    DISPLAYSURF.blit(levelSurf, levelRect)


def drawCursor(cursor, pixelx=None, pixely=None):
    shapeToDraw = CURSOR_TEMPLATE
    if pixelx == None and pixely == None:
        # if pixelx & pixely hasn't been specified, use the location stored in the piece data structure
        pixelx, pixely = convertToPixelCoords(cursor['x'], cursor['y'])

    # draw each of the boxes that make up the piece
    for x in range(TEMPLATEWIDTH):
        for y in range(TEMPLATEHEIGHT):
            if shapeToDraw[y][x] != BLANK:
                drawBox(None, None, 0, pixelx + (x * BOXSIZE), pixely + (y * BOXSIZE))


if __name__ == '__main__':
    main()
