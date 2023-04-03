#include "library.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    //welcomeMenu();
    n = getCard();
    cout << getCardChar(n);
    cout << getCardVal(n);
}