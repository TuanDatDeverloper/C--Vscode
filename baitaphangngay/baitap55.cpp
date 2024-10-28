/*
A young, poor farmer has n hunting dogs. Each hunting dog has three attributes: weight, in-
telligence, and market value. One day, the farmer needs to sell some of his hunting dogs to raise
money for his wedding. The farmer has found a billionaire who has enough money to buy the dogs.
However, the billionaire wants to select the hunting dogs that satisfy the following condition: two
hunting dogs p and q can both be chosen if the weight of dog p is greater than or equal to that of
dog q, then the intelligence of dog p must be at least equal to that of dog q and vice versa. Help
the farmer choose the hunting dogs to sell in a way that will maximize the total money earned.
Input
• Line 1: one positive integer n (1 ≤ n ≤10000)
• Line 2 to (n+1): each line consists of 3 integers separated by spaces, representing the weight,
intelligence, and utility value of a hunting dog (the values of the integers are in the range
[1, 10000])
Output
A single positive integer is the maximum total market value of the selected hunting dogs
Sample Input
7
2300 7 10
2000 13 40
2800 13 40
2100 11 50
2500 6 20
2600 9 15
2000 17 50
Sample Output
90
giải bằng C++ khi làm contest
*/
#include <bits/stdc++.h>

struct Dog {
    int weight;
    int intelligence;
    int marketValue;
};

bool compare(Dog a, Dog b) {
    return a.weight > b.weight;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
    int n;
    std::cin >> n;

    std::vector<Dog> dogs(n);

    for (int i = 0; i < n; i++) {
        std::cin >> dogs[i].weight >> dogs[i].intelligence >> dogs[i].marketValue;
    }

    std::sort(dogs.begin(), dogs.end(), compare);

    std::vector<int> dp(n);
    int maxTotalMarketValue = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = dogs[i].marketValue;
        for (int j = 0; j < i; j++) {
            if (dogs[j].intelligence >= dogs[i].intelligence) {
                dp[i] = std::max(dp[i], dp[j] + dogs[i].marketValue);
            }
        }
        maxTotalMarketValue = std::max(maxTotalMarketValue, dp[i]);
    }

    std::cout << maxTotalMarketValue << std::endl;

    return 0;
}
