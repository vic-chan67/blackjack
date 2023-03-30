#include <iostream>

using namespace std;

int main() {
    int arr[52]; // declare an array of size 52

    // initialize the first 13 elements with numbers 1 to 13
    for (int i = 0; i < 13; i++) {
        arr[i] = i + 1;
    }

    // repeat the sequence 1 to 13 until the array is fully initialized
    for (int i = 13; i < 52; i++) {
        arr[i] = arr[i - 13];
    }

    // print the array
    for (int i = 0; i < 52; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
