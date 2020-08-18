import abc

class LaserActionAbstract:
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def do_action(self, lastX, lastY, curDirection):
        raise NotImplementedError

class empty_action(LaserActionAbstract):
    def do_action(self, lastX, lastY, curDirection):
        if curDirection == 'N':
            return lastX, lastY+1
        elif curDirection == 'S':
            return lastX, lastY-1
        elif curDirection == 'E':
            return lastX+1, lastY
        elif curDirection == 'W':
            return lastX-1, lastY
        else:
            raise TypeError
