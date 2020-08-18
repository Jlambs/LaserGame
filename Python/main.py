from Board import Board

def main():
    board = Board(5, 5)
    board.set_tile(2, 5, 'cannon', 'N', 1, 1)
    board.printBoard()



if __name__ == '__main__':
    main()
