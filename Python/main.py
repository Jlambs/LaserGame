from GameController import GameController
from Board import Board

def main():
    ''' Testing beam mechanics and object placement/change
        5x5 board
    board = Board(5, 5)
    board.set_tile(2, 4, 'cannon', 'N', 1, 1)
    board.set_tile(2, 1, 'mirror', 'pos', 1, 1)
    board.set_tile(4, 1, 'mirror', 'neg', 0, 0)
    board.set_tile(4, 4, 'mirror', 'pos', 0, 0)

    board.printBoard()
    response = board.updateLaser(2, 4, 2, 3)
    print(response)
    '''

    ''' Testing game with GameController
    '''
    game = GameController(5, 5, 2)


if __name__ == '__main__':
    main()
