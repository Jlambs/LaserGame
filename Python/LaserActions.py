import abc

class LaserActionAbstract:
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def do_action(self, lastX, lastY, curDirection):
        raise NotImplementedError

class EmptyAction(LaserActionAbstract):
    def do_action(self, lastX, lastY, curDirection, mirrorSlope):
        if curDirection == 'N':
            return lastX, lastY-1
        elif curDirection == 'S':
            return lastX, lastY+1
        elif curDirection == 'E':
            return lastX+1, lastY
        elif curDirection == 'W':
            return lastX-1, lastY
        else:
            raise TypeError

class MirrorAction(LaserActionAbstract):
    def do_action(self, lastX, lastY, curDirection, mirrorSlope):
        if mirrorSlope == 'pos':
            if curDirection == 'N':
                return lastX+1, lastY
            elif curDirection == 'S':
                return lastX-1, lastY
            elif curDirection == 'E':
                return lastX, lastY-1
            elif curDirection == 'W':
                return lastX, lastY+1
        elif mirrorSlope == 'neg':
            if curDirection == 'N':
                return lastX-1, lastY
            elif curDirection == 'S':
                return lastX+1, lastY
            elif curDirection == 'E':
                return lastX, lastY+1
            elif curDirection == 'W':
                return lastX, lastY-1
        else:
            raise TypeError

class CannonAction(LaserActionAbstract):
    def do_action(self, lastX, lastY, curDirection, mirrorSlope):
        return "HIT", None
