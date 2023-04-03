// Functions are ordered alphabetically
#include "library.hpp"
#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

int wChip = 20, rChip = 10, oChip = 5, gChip = 3, bChip = 1;
int deck[52] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
vector<int> pHand, dHand;
int bet[5];

void betChip() {
    int w, r, o, g, b, total;
    int loop = 0;
    countChips();
    cout << "\n!! Place your bets !!";
    while (loop != 1) {
        char choice, ans; int num;
        cout << "\nWhich chip do you want to use? (w/r/o/g/b) ";
        cin >> choice;
        cout << "How many chips do you want to bet? (any number) ";
        cin >> num;
        if (choice == 'w' || choice == 'W') {
            bet[0] = num;
        } else if (choice == 'r' || choice == 'R') {
            bet[1] = num;
        } else if (choice == 'o' || choice == 'O') {
            bet[2] = num;
        } else if (choice == 'g' || choice == 'G') {
            bet[3] = num;
        } else if (choice == 'b' || choice == 'B') {
            bet[4] = num;
        } else {
            cout << "\n!! Invalid input !! Terminating game !!";
            exit(1);
        }
        total = bet[0] + (bet[1]*5) + (bet[2]*10) + (bet[3]*25) + (bet[4]*100);
        cout << "\nCurrent betting total: £" << total;
        cout << "\nDo you want to bet more? (y/n) ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            loop = 0;
        } else {
            loop = 1;
        }
    }
}

void cardToHand(int pd, int card) {
    if (pd == 0) {
        pHand.push_back(card);
    } else {
        dHand.push_back(card);
    }
}

int checkScore(int pd, int score) {
    cout << "\nHand score: " << score;
    if (score < 21) {
        if (pd == 0) {
            hitStandP();
        } else {
            hitStandD();
        }
        return 0;
    } else if (score == 21) {
        return 1;
    } else {
        return 0;
    }
}

void chipCounter(int wNew, int rNew, int oNew, int gNew, int bNew) {
    wChip += wNew;
    rChip += rNew;
    oChip += oNew;
    gChip += gNew;
    bChip += bNew;
}

int compareHands() {
    int pScore, dScore;
    pScore = handScore(0);
    dScore = handScore(1);

    cout << "\n\nYour score: " << pScore;
    cout << "\nDealer's score: " << dScore;

    if (pScore > dScore && pScore <= 21) {
        cout << "\n!! Well done, you've won !!";
        return 1;
    } else if (pScore > dScore && pScore > 21) {
        cout << "\n!! Oh no, you've lost !!";
        return -1;
    } else if (pScore < dScore) {
        cout << "\n!! Oh no, you've lost !!";
        return -1;
    } else {
        cout <<"\n!! A draw !!";
        return 0;
    }
}

void countChips() {
    int total;
    total = wChip + (rChip*5) + (oChip*10) + (gChip*25) + (bChip*100);
    cout << "\n*******************************";
    cout << "\nTotal money: £" << total;
    cout << "\n   White chips (£1): " << wChip;
    cout << "\n   Red chips (£5): " << rChip;
    cout << "\n   Orange chips (£10): " << oChip;
    cout << "\n   Green chips (£25): " << gChip;
    cout << "\n   Black chips (£100): " << bChip;
    cout << "\n*******************************\n\n";
}

int getCard() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 51);
    int num = dis(gen);
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
    //cout << "\ncard: " << card;
    int cardVal;
    if (card > 10) {
        cardVal = 10;
    } else if (card == 1) {
        int choice;
        cout << "\nYou have an ace! Do you want it to be counted as 1 or 11? (1/11) ";
        cin >> choice;
        if (choice == 1 || choice == 11) {
            cardVal = choice;
        } else {
            cout << "!! Invalid input !! Terminating game !!";
            exit(1);
        }
    } else {
        cardVal = card;
    } return cardVal;
}

int handScore(int pd) {
    int score = 0;
    if (pd == 0) {
        for (int i = 0; i < pHand.size(); i++) {
            score += getCardVal(pHand[i]);
            //cout << "\nScore: " << score;
        }
    } else {
        for (int i = 0; i < dHand.size(); i++) {
            score += getCardVal(dHand[i]);
        }
    }
    return score;
}

void hitStandD() {

}

void hitStandP() {
    int score = handScore(0);
    while (score < 21) {
        char choice;
        cout << "\nHit or Stand? (h/s) ";
        cin >> choice;
        if (choice == 'h' || choice == 'H') {
            cardToHand(0, getCard());
            printHand(0);
            score = handScore(0);
            cout << "\nHand score: " << score;
        } else {
            cout << "\n!! Final hand !!";
            printHand(0);
            cout << "\nHand score: " << score;
            break;
        }
    }
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

void printHand(int pd) {
    string hand;
    string card;
    if (pd == 0) {
        for (int i = 0; i < pHand.size(); i++) {
            card = getCardChar(pHand[i]);
            hand += card + " ";
        }
        hand.pop_back();
        cout << "\nYour hand: " << hand; 
    } else {
        for (int i = 0; i < dHand.size(); i++) {
            card = getCardChar(dHand[i]);
            hand += card + " ";
        }
        hand.pop_back();
        cout << "\n\nDealer's hand: " << hand;
    }
}

void winnings(int win) {
    int w, r, o, g, b;
    w = bet[0]; r = bet[1]; o = bet[2]; g = bet[3]; b = bet[4];
    if (win == 1) {
        chipCounter(w, r, o, g, b);
    } else if (win == -1) {
        chipCounter(-w, -r, -o, -g, -b);
    } else {
        chipCounter(0, 0, 0, 0, 0);
    }
}

void gameRound() {
    pHand.clear(); dHand.clear();
    // 0 for pHand, 1 for dHand
    betChip();
    for (int i = 0; i < 5; i++) {
        cout << "\n" << bet[i];
    }
    cardToHand(0, getCard());
    cardToHand(1, getCard());
    cardToHand(0, getCard());
    cardToHand(1, getCard());
    printHand(0);
    checkScore(0, handScore(0));
    printHand(1);
    int w = compareHands();
    winnings(w);
    countChips();
    
    char ans;
    cout << "\n\nPlay another round? (y/n) ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y') {
        gameRound();
    } else {
        exit(1);
    }
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
