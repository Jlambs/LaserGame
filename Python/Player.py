class Player():

    p_name = 'No Name Specified'

    def get_name(self):
        return self.p_name

    def set_name(self, newName):
        self.p_name = newName


    def __init__(self, name):
        self.set_name(name)
