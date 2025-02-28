#include <bits/stdc++.h>
using namespace std;

void inputData(int* p, int n) {
    srand(static_cast<unsigned int>(time(0)));
    for (int* ptr = p; ptr < p + n; ptr++) {
        *ptr = rand() % 100;
    }
}

void printArray(int* p, int n) {
    cout << "Mang: ";
    for (int* ptr = p; ptr < p + n; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;

    int* arr = new int[n];

    inputData(arr, n);
    printArray(arr, n);

    delete[] arr;
    return 0;
}