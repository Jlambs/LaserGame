from Tile import Tile

class Board():
    # # TODO:  Impliment Board
    ''' Define variables for the board and appropriate getters and setters
    '''
    tile_grid = {}
    max_x = -1
    max_y = -1

    def get_max_x(self):
        return max_x;
    def set_max_x(self, newX):
        max_x = newX
    def get_max_y(self):
        return max_y;
    def set_max_y(self, newY):
        max_y = newY

    ''' Builds the grid as a nested dictionary of size (xBound, yBound)
        yBound (int) :: Specifies number of rows in dictionary
        xBound (int) :: Specifies number of columns in dictionary
    '''
    def build_grid(self, xBound, yBound):
        for i in range(0, yBound):
            tile_grid[i] = {}
            for j in range(0, xBound):
                tile_grid[i][j] = Tile()


    ''' Define the initializing function for a board
        specifies the size of the grid and number of players
            xBound (int) :: Specifies the width of the board
            yBound (int) :: Specifies the height of the board
    '''
    def __init__(self, xBound, yBound):
        self.set_max_x(xBound)
        self.set_max_y(yBound)
        self.build_grid(xBound, yBound)

    
