from LaserActions import *

class Tile():
    ''' Define the different actions a tile can take so we can swap them out
        later
    '''
    empty_action = EmptyAction()
    mirror_action = MirrorAction()
    cannon_action = CannonAction()

    ''' Define variables for tiles name and type as well as appropriate
        getters and setters
    '''
    direction = 'Unspecified Direction'
    type = 'Unspecified Type'
    type_fixed = -1
    direction_fixed = -1
    def get_direction(self):
        return self.direction
    def set_direction(self, newDir):
        self.direction = newDir
    def get_type(self):
        return self.type

    ''' Define a function that will change the type of a tile, in doing so this
        will also change the strategy used in determining beam behavior
    '''
    def set_type(self, newType, newDirection):
        if newType == 'Empty':
            self.type = '.'
            self.set_laser_action(self.empty_action)
        elif newType == 'cannon':
            self.type = '|'
            self.set_laser_action(self.cannon_action)
        elif newType == 'mirror':
            if newDirection == 'pos':
                self.type = '/'
                self.direction = 'pos'
                self.set_laser_action(self.mirror_action)
            elif newDirection == 'neg':
                self.type = '\\'
                self.direction = 'neg'
                self.set_laser_action(self.mirror_action)
            else:
                raise TypeError
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
        self.set_type(initType, initDirection)
        self.set_direction(initDirection)
        self.type_fixed = isTypeFixed
        self.direction_fixed = isDirectionFixed


    ''' Define a laserAction  variable that will be set when initializing the
        tile with an appropriate setter. This is a part of a Stragety Pattern
        to seperate the laser behavior of tiles from the tiles themselves.
    '''
    laser_action = LaserActionAbstract()

    # Sets the behavior of the tile
    def set_laser_action(self, newLaserAction):
        self.laser_action = newLaserAction

    # Returns the x and y position of the next tile the laser will move to
    @abc.abstractmethod
    def propegate_laser(self, lastX, lastY, curDirection):
        return self.laser_action.do_action(lastX, lastY, curDirection, self.get_direction())
