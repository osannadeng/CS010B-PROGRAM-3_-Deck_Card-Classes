#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);

void fillHand(Deck &, vector<Card> &, unsigned);

double monteCarlo(int, vector<Card> &, Deck &, unsigned, bool, string);

int main() {
    srand(2222);
    
    string ans;
    bool oF = false;
    string outName;
    unsigned cardsPerHand;
    int numDeals;
    vector<Card> hand;
    Deck d = Deck();

    cout << "Do you want to output all hands to a file? (Yes/No) ";
    cin >> ans;
    cout << endl << endl;
    if (ans == "Yes") {
        oF = true;
        cout << "Enter name of output file: ";
        cin >> outName;
        cout << endl << endl;
    }
    cout << "Enter number of cards per hand: ";
    cin >> cardsPerHand;
    cout << endl << endl;
    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl << endl;

    cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << monteCarlo(numDeals, hand, d, cardsPerHand, oF, outName) << "%" << endl;

    return 0;
}

bool hasPair(const vector<Card> &hand) {
    for (unsigned i = 0; i < hand.size(); ++i) {
        for (unsigned j = 0; j < hand.size(); ++j) {
            if (hand.at(i).getRank() == hand.at(j).getRank() && i != j) {
                return true;
            }
        }
    }
    return false;
}

ostream & operator<<(ostream &o, const vector<Card> &v) {
    for (unsigned i = 0; i < v.size(); ++i) {
        o << v.at(i);
        if (i < v.size() - 1) {
            o << ", ";
        }
    }
    return o;
}

void fillHand(Deck &d, vector<Card> &hand, unsigned numCards) {
    d.shuffleDeck();
    hand = vector<Card> (0);
    for (unsigned i = 0; i < numCards; ++i) {
        hand.push_back(d.dealCard());
    }
}


double monteCarlo(int deals, vector<Card> &hand, Deck &d, unsigned numCards, bool oF, string outName) {
    double pairs = 0.0;
    ofstream outFS;
    if (oF) {
        outFS.open(outName);
        
        if (!outFS.is_open()) {
            return 0;
        }
    }
    for (int i = 0; i < deals; ++i) {
        fillHand(d, hand, numCards);
        if (hasPair(hand)) {
            ++pairs;
        }
        if (oF) {
            if (hasPair(hand)) {
                outFS << "Found Pair!! ";
            } else {
                outFS << "             ";
            }
            outFS << hand << endl;
        }
    }

    outFS.close();

    return (pairs / (double) deals) * 100;
}