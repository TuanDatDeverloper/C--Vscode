#include <iostream>

int main() {
    long long sum = 0;
    long long number;

    while (true) {
        std::cin >> number;
        if (number == 0) {
            break;
        }
        sum += number;
    }

    std::cout << sum << std::endl;
    return 0;
}
