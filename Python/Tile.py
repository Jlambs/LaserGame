from LaserActions import *

class Tile():
    ## TODO: Impliment Tile
    ''' Define variables for tiles name and type as well as appropriate
        getters and setters
    '''
    direction = 'Unspecified Direction'
    type = 'Unspecified Type'
    type_fixed = -1
    direction_fixed = -1
    def get_direction(self):
        return direction
    def set_direction(self, newDir):
        self.direction = newDir
    def get_type(self):
        return type
    def set_type(self, newType):
        if newType == 'Empty':
            self.type = '.'
        elif newType == 'cannon':
            self.type = '|'
        else:
            raise TypeError


    ''' Define the initializing method that will create each Tile object.
        This will set the direction and type of the Tile.
            initDirection    :: Specifies initial direction of tiles
            initType         :: Defines the initial type of the tiles
            isTypeFixed      :: 0 if type can't be changed, 1 if it can
            isDirectionFixed :: 0 if direction can't be changed, 1 if it can
    '''
    def __init__(self, initDirection, initType, isTypeFixed, isDirectionFixed):
        self.set_type(initType)
        self.set_direction(initDirection)
        self.type_fixed = isTypeFixed
        self.direction_fixed = isDirectionFixed


    ''' Define a laserAction  variable that will be set when initializing the
        tile with an appropriate setter. This is a part of a Stragety Pattern
        to seperate the laser behavior of tiles from the tiles themselves.
    '''
    laser_action = LaserActionAbstract()

    # Sets the behavior of the tile
    def setLaserAction(self, newLaserAction):
        self.laser_action = newLaserAction

    # Returns the x and y position of the next tile the laser will move to
    @abc.abstractmethod
    def propegate_laser(self, lastX, lastY, curDirection):
        return self.laser_action.do_action(lastX, lastY, curDirection)
