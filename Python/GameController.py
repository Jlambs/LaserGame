from Player import Player
from Board import Board
from ViewController import ViewController

class GameController():

    board = None
    players = {}
    player_locations = {}
    turn_number = 0

    ''' Initializes the GameController, this will link with a player and recieve
        inputs on what to do.
    '''
    def __init__(self, boardWidth, boardHeight, numPlayers):
        self.board = Board(boardWidth, boardHeight)
        self.board.set_tile(round(boardWidth/2), round(boardHeight/2), 'mirror', 'pos', 1, 1)
        for i in range(numPlayers):
            p_name = input("Enter Player: "+str(i+1)+"'s Name: ")
            self.players[i] = Player(p_name)
            # Set up checkers for input validation
            p_locX = -1
            p_locY = -1
            p_dir = 'None'
            # Get the X coordinate of the player
            invalid_input = 1
            while(invalid_input):
                p_locX = int(input("Enter "+p_name+"'s' X Coordinate: "))
                if (p_locX >= 0) and (p_locX < boardWidth):
                    invalid_input = 0
            # Get the Y coordinate of the player
            invalid_input = 1
            while(invalid_input):
                p_locY = int(input("Enter "+p_name+"'s' Y Coordinate: "))
                if (p_locY >= 0) and (p_locY < boardHeight):
                    invalid_input = 0
            # Get the direction of the player
            invalid_input = 1
            while(invalid_input):
                p_dir = input("Enter "+p_name+"'s' Direction (N/S/E/W): ")
                if p_dir in ['N', 'E', 'S', 'W']:
                    invalid_input = 0
            self.player_locations[i] = [p_locX, p_locY, p_dir]
        self.spawn_players()

    ''' Spawn the players
    '''
    def spawn_players(self):
        for i in self.players:
            p_locX, p_locY, p_dir = self.player_locations[i]
            self.board.set_tile(p_locX, p_locY, 'cannon', p_dir, 1, 1)
        self.board.printBoard()

    ''' This function will control the logic of each turn, the correct player
        will be chosen and a input for their turn will go out. The turn will
        either reject the input and ask again, or perform the action, fire the
        laser, and check for win conditions.
    '''
