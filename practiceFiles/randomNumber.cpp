#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main()
{
    // Use the current time as a seed for rand()
    srand(time(NULL));

    // Generate a random number between 0 and 51
    int randomNumber = rand() % 52;

    cout << "Random number between 0 and 51: " << randomNumber;

    return 0;
}
