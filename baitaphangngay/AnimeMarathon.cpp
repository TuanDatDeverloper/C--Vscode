/*
Vivek and Sagar are at an anime marathon, where there are n
anime episodes lined up for them to watch. Each anime episode has a unique enjoyment value, denoted as ai
for the i-th episode.
The two friends take turns watching episodes, with Vivek going first:
On his turn, Vivek can only watch an episode whose enjoyment value is strictly greater than the highest enjoyment value of all the episodes he has already watched. On his first turn, he can pick any episode he likes.
On his turn, Sagar picks any of the remaining episodes and watches it, without any restrictions on the enjoyment value.
The marathon continues until neither can select a suitable episode to watch. Let x represent the total number of episodes Vivek manages to watch. While Vivek is eager to watch as many episodes as possible, Sagar's goal is to minimize the number of episodes Vivek gets to enjoy.
Determine how many episodes Vivek will end up watching if both play optimally.
Input
Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤10) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n(1≤n≤15) — the number of episodes.
The second line of each test case contains n integers a1,a2,…,an(1≤ai≤n) — the enjoyment values of the episodes.
It is guaranteed that the sum of n over all test cases does not exceed 15.
Output
For each test case, output a single integer — the number of episodes Vivek will watch if both players play optimally.
Example
Input
10
15
11 8 7 8 3 15 7 15 2 1 1 9 8 2 4
15
11 14 15 1 14 4 1 1 13 8 2 6 1 15 12
15
9 3 9 12 15 5 15 2 1 15 5 14 4 6 9
15
6 15 11 7 12 3 1 13 5 15 10 5 4 4 3
15
13 6 2 4 13 4 8 7 11 11 13 15 7 10 2
15
5 13 15 13 7 5 7 5 4 15 1 8 14 1 12
15
7 3 9 13 4 9 4 1 8 8 11 13 2 8 9
15
15 6 4 12 2 3 14 8 11 8 8 14 3 3 11
15
8 8 2 15 1 10 8 2 10 9 10 12 2 13 7
15
3 9 2 9 6 6 15 15 4 11 5 10 14 3 14
Output
5
6
6
6
5
5
5
5
5
6

*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int dp[1 << MAXN][MAXN + 1][2]; // Tăng kích thước để chứa giá trị từ 0 đến 15
int n;
vector<int> a;

int solve(int mask, int last, int turn) {
    if (dp[mask][last][turn] != -1) return dp[mask][last][turn];
    
    // Nếu không còn tập phim nào để xem
    bool anyMovePossible = false;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            anyMovePossible = true;
            break;
        }
    }
    if (!anyMovePossible) return 0;

    if (turn == 0) { // Lượt của Vivek
        int best = 0;
        bool canWatch = false;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)) && a[i] > last) {
                canWatch = true;
                best = max(best, 1 + solve(mask | (1 << i), a[i], 1));
            }
        }
        if (!canWatch) best = solve(mask, last, 1);
        return dp[mask][last][turn] = best;
    } else { // Lượt của Sagar
        int worst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                worst = min(worst, solve(mask | (1 << i), last, 0));
            }
        }
        return dp[mask][last][turn] = worst;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 0) << endl;
    }
    return 0;
}
// Time complexity: O(2^n * n^2)
