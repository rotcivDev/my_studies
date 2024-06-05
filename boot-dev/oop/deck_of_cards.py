import random

def main():
    print('create new deck')
    my_deck = DeckOfCards()
    print('print deck')
    my_deck.log_deck()
    print('shuffle and print')
    my_deck.shuffle_deck()
    my_deck.log_deck()

class DeckOfCards:
    SUITS = ["Hearts", "Diamonds", "Clubs", "Spades"]
    RANKS = [
        "Ace",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "Jack",
        "Queen",
        "King",
    ]

    def __init__(self):
        self.__cards = list(self.create_deck())

    def create_deck(self):
        new_deck = list()
        for suit in self.SUITS:
            for rank in self.RANKS:
               new_deck.append((rank, suit))

        return new_deck

    def log_deck(self):
        print(self.__cards)

    def shuffle_deck(self):
        random.shuffle(self.__cards)

    def deal_card(self):
        if len(self.__cards) <= 0: return None
        return self.__cards.pop()

    # don't touch below this line

    def __str__(self):
        return f"The deck has {len(self.__cards)} cards"

main()
