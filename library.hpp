#pragma once
#include <string>

void betChip();
void cardToHand(int pd, int card);
int checkScore(int pd, int score);
void chipCounter(int wNew, int rNew, int oNew, int gNew, int bNew);
int compareHands();
void countChips();
void gameRound();
int getCard();
char getCardChar(int card);
int getCardVal(int card);
int handScore(int pd);
void hitStandD();
void hitStandP();
void howToPlay();
void payoutRule();
void printHand(int pd);
void welcomeMenu();
void winnings(int w);
