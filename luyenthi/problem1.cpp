#include <bits/stdc++.h>
using namespace std;

void inputData(int* p, int n) {
    srand(static_cast<unsigned int>(time(0)));
    for (int* ptr = p; ptr < p + n; ptr++) {
        *ptr = rand() % 100;
    }
}

void printArray(int* p, int n) {
    cout << "Array: ";
    for (int* ptr = p; ptr < p + n; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}

int removeOdd(int* p, int n) {
    int* writePtr = p;
    for (int* readPtr = p; readPtr < p + n; readPtr++) {
        if((*readPtr) % 2 == 0) {
            *writePtr = *readPtr;
            writePtr++;
        }
    }
    return writePtr - p;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* A = new int[n];

    inputData(A, n);
    cout << "Original ";
    printArray(A, n);

    int newSize = removeOdd(A, n);
    cout << "After removing odd numbers ";
    printArray(A, newSize);

    delete[] A;
    return 0;
}
