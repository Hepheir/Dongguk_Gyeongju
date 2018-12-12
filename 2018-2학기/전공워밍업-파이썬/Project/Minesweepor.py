# 지뢰찾기를 하는 프로그램

import time

from subprocess import Popen, PIPE

FPS = 2

GAME_SOURCE_PATH = 'Minesweeper.py'

def main():
    global PROC

    runGame()
    x = 0
    y = 0

    with PROC as p:
        for line in p.stdout:
            print(line, end='')



def runGame():
    global PROC
    PROC = Popen(['python3', GAME_SOURCE_PATH],
        stdout=PIPE,
        bufsize=1,
        universal_newlines=True
    )


def delay():
    time.sleep(1/FPS)

main()