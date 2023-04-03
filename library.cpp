// Functions are ordered alphabetically
#include "library.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int wChip = 20, rChip = 10, oChip = 5, gChip = 3, bChip = 1;
int deck[52] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void chipCounter(int wNew, int rNew, int oNew, int gNew, int bNew) {
    wChip += wNew;
    rChip += rNew;
    oChip += oNew;
    gChip += gNew;
    bChip += bNew;
}

void countChips() {
    int total;
    total = wChip + (rChip*5) + (oChip*10) + (gChip*25) + (bChip*100);
    cout << "\n******************************************************************";
    cout << "\nTotal money: £" << total;
    cout << "\n   White chips (£1): " << wChip;
    cout << "\n   Red chips (£5): " << rChip;
    cout << "\n   Orange chips (£10): " << oChip;
    cout << "\n   Green chips (£25): " << gChip;
    cout << "\n   Black chips (£100): " << bChip;
    cout << "\n******************************************************************\n\n";
}

int getCard() {
    int cardVal;
    srand(time(NULL));
    int num = rand() % 52;
    int card = deck[num];
    return card;
}

char getCardChar(int card) {
    char cardChar;
    switch (card) {
        case 1: cardChar = 'A'; break;
        case 2: cardChar = '2'; break;
        case 3: cardChar = '3'; break;
        case 4: cardChar = '4'; break;
        case 5: cardChar = '5'; break;
        case 6: cardChar = '6'; break;
        case 7: cardChar = '7'; break;
        case 8: cardChar = '8'; break;
        case 9: cardChar = '9'; break;
        case 10: cardChar = 'T'; break;
        case 11: cardChar = 'J'; break;
        case 12: cardChar = 'Q'; break;
        case 13: cardChar = 'K'; break;
    } return cardChar;
}

int getCardVal(int card) {
    int cardVal;
    if (card == 11 || card == 12 || card == 13) {
        cardVal = 10;
    } else if (card == 1) {
        int choice;
        cout << "You have an ace! Do you want it to be counted as 1 or 11? (1/11) ";
        cin >> choice;
        cardVal = choice;
    } else {
        cardVal = card;
    } return cardVal;
}

void howToPlay() {
    cout << "\n******************************************************************";
    cout << "\nHow to play:\nYou are playing against the dealer (computer)\n";
    cout << "Your goal is to get as close to 21 as possible\nAll numbered cards hold their value\n";
    cout << "Jack, Queen and King are all worth 10\nAce is worth 1 or 11\n";
    cout << "   You will be asked which value you want your Ace to hold\n";
    cout << "After receiving your two cards, you can either hit or stand\n   Hit - you want another card\n";
    cout << "   Stand - you do not want another card, ending your turn\n";
    cout << "If your score is above 21, you have a bust\n   You automatically lose the round\n";
    cout << "If you haven't got a bust, the dealer has their turn\n   Dealer bust - you win\n";
    cout << "   Dealer doesn't bust - highest score wins\n";
    cout << "Ace = A, 10 = T, Jack = J, Queen = Q, King = K\n";
    cout << "******************************************************************\n\n";
}

void payoutRule() {
    cout << "\n******************************************************************";
    cout << "\nChips and payouts:\nYou begin with five different chips:\n   White = £1\n   Red = £5\n";
    cout << "   Orange = £10\n   Green = £25\n   Black = £100\n";
    cout << "   You have 20 white, 10 red, 5 orange, 3 green, and 1 black chip\n";
    cout << "Each round begins with you specifying an amount to bet\n";
    cout << "If you win by scoring higher (from hit and stands), it's a 1:2 payout\n";
    cout << "   Example: You bet 1 green, you win 2 greens (dealer gives 1 green to you)\n";
    cout << "If you win with 21 from two cards, it's a 1:4 payout\n";
    cout << "   Example: You bet 1 green, you win 4 greens (dealer gives 3 greens to you)\n";
    cout << "If you lose, your bet is taken and you receive nothing\n";
    cout << "******************************************************************\n\n";
}

void welcomeMenu() {
    char ansHow, ansPay;
    cout << "******************************************************************";
    cout << "\nWelcome to BLACKJACK, coded up by Victoria Chan\n";
    cout << "!! WARNING !! Keyboard inputs during the game must be valid otherwise the game will close !!\n";
    cout << "Would you like to hear how to play the game? (y/n) ";
    cin >> ansHow;
    if (ansHow == 'y' || ansHow == 'Y') {
        howToPlay();
    } else if (ansHow == 'n' || ansHow == 'N') {
    } else {
        cout << "!! Invalid response !! How to play will be skipped !!\n\n";
    }
    cout << "Would you like to hear how the chips and payouts work? (y/n) ";
    cin >> ansPay;
    if (ansPay == 'y' || ansPay == 'Y') {
        payoutRule();
    } else if (ansPay == 'n' || ansPay == 'N') {
    } else {
        cout << "!! Invalid response !! Chips and payout rules will be skipped !!\n\n";
    }
}
