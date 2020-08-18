from Tile import Tile

class Board():
    # # TODO:  Impliment Board
    ''' Define variables for the board and appropriate getters and setters
    '''
    tile_grid = {}
    max_x = -1
    max_y = -1

    def get_max_x(self):
        return self.max_x;
    def set_max_x(self, newX):
        self.max_x = newX
    def get_max_y(self):
        return self.max_y;
    def set_max_y(self, newY):
        self.max_y = newY

    ''' Builds the grid as a nested dictionary of size (xBound, yBound)
        yBound (int) :: Specifies number of rows in dictionary
        xBound (int) :: Specifies number of columns in dictionary
    '''
    def build_grid(self, xBound, yBound):
        for i in range(0, yBound):
            self.tile_grid[i] = {}
            for j in range(0, xBound):
                self.tile_grid[i][j] = Tile("None", "Empty", 0, 1)

    def get_tile(self, x, y):
        return self.tile_grid[y][x]

    def set_tile(self, x, y, tileType, initDirection, isDirectionFixed, isTypeFixed):
        self.tile_grid[y][x] = Tile(initDirection, tileType, isTypeFixed, isDirectionFixed)


    ''' Define the initializing function for a board
        specifies the size of the grid and number of players
            xBound (int) :: Specifies the width of the board
            yBound (int) :: Specifies the height of the board
    '''
    def __init__(self, xBound, yBound):
        self.set_max_x(xBound)
        self.set_max_y(yBound)
        self.build_grid(xBound, yBound)

    def printBoard(self):
        for i in range(self.get_max_y()):
            rowString = ""
            for j in range(self.get_max_x()):
                rowString += self.get_tile(j, i).get_type()
            print(rowString)


    def updateLaser(self, lastX, lastY, curX, curY):
        # Determine the direction the beam is moving
        curDirection = 'None'
        if (curX - lastX == -1):
            curDirection = 'W'
        elif (curX - lastX == 1):
            curDirection = 'E'
        elif (curY - lastY == -1):
            curDirection = 'N'
        elif (curY - lastY == 1):
            curDirection = 'S'

        print(["curX:", curX, "curY:", curY, "lastX:", lastX, "lastY:", lastY])

        # Get coords of next tile to check
        nextX, nextY = self.get_tile(curX, curY).propegate_laser(curX, curY, curDirection)
        # Do bounds checking to see if laser extends beyond edges
        if (nextX == 'HIT'):
            return "Cannon Destroyed"
        elif (nextX >= self.get_max_x()) or (nextX < 0) or (nextY >= self.get_max_y() or (nextY < 0)):
            return ["Hit Edge", nextX, nextY]
        else:
            return self.updateLaser(curX, curY, nextX, nextY)
