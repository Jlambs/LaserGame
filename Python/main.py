from GameController import GameController


def main():

    animals = [Wolf('Wendy'), Dog('Doug'), Crow('Cathy'), Vulture('Vick'), Cat('Carl'), Lion('Leo')]
    keeper = ZooKeeper(animals)
    announcer = ZooAnnoucer()

    keeper.registerObserver(announcer)
    keeper.performResponsibilities()
    keeper.removeObserver(announcer)


if __name__ == '__main__':
    main()
