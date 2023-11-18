#include <algorithm>

#include "Deck.h"

Deck::Deck() {
    char suit;
    for (unsigned j = 0; j < 4; ++j) {
        for (unsigned i = 13; i > 0; --i) {
            if (j == 0) {
                suit = 's';
            } else if (j == 1) {
                suit = 'h';
            } else if (j == 2) {
                suit = 'd';
            } else {
                suit = 'c';
            }
            theDeck.push_back(Card(suit, i));
        }
    }
}

Card Deck::dealCard() {
    dealtCards.push_back(theDeck.back());
    theDeck.pop_back();
    return dealtCards.back();
}

void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards = vector<Card> (0);
    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const {
    return theDeck.size();
}