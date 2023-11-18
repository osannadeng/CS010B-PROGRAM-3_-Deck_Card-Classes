#include "Card.h"

Card::Card() {
    rank = 2;
    suit = 'c';
}

Card::Card(char s, int r) {
    rank = r;
    suit = s;
    if (s != 'c' && s != 'C' && s != 'd' && s != 'D' && s != 's' && s != 'S' && s != 'h' && s != 'H') {
        cout << "Invalid suit: Fixed to Clubs" << endl;
        suit = 'c';
    }
    if (suit == 'C') {
        suit = 'c';
    } else if (suit == 'D') {
        suit = 'd';
    } else if (suit == 'S') {
        suit = 's';
    } else if (suit == 'H') {
        suit = 'h';
    }
    if (r < 1 || r > 13) {
        cout << "Invalid rank: Fixed to 2" << endl;
        rank = 2;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &o, const Card &c) {
    string suitName;
    if (c.suit == 'c') {
        suitName = "Clubs";
    } else if (c.suit == 'd') {
        suitName = "Diamonds";
    } else if (c.suit == 's') {
        suitName = "Spades";
    } else if (c.suit == 'h') {
        suitName = "Hearts";
    }
    if (c.rank > 1 && c.rank < 11) {
        o << c.rank << " of " << suitName;
    } else if (c.rank == 1) {
        o << "Ace of " << suitName;
    } else if (c.rank == 11) {
        o << "Jack of " << suitName;
    } else if (c.rank == 12) {
        o << "Queen of " << suitName;
    } else if (c.rank == 13) {
        o << "King of " << suitName;
    }
    return o;
}