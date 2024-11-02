/*
You are given a string of n characters
You need to find the length of the shortest substring that contains all letters 'h', 'a', 'r', 'd', 'w', 'o', 'r', 'k' in any order
Note that you the substring needs to contain two 'r'
If no substring exists which contains all these letters, print -1
Input
First line consists of a single integer t, number of tests(1≤t≤1000)
First line of each test consists of single integer n, size of string(1≤n≤10^5)
Second line of each test consists of the word
Output
For each test, print the length of the shortest substring that contains the letters 'h', 'a', 'r', 'd', 'w', 'o', 'r', 'k'
Example
Input
9
8
hardwork
7
hardwok
15
rwkrhhkkaokdrrw
15
kdrrwdoaahdoadw
15
dwororaohrkaaor
15
hhawdkowdhwarak
15
rarraakhaorkadh
15
rkrwawoarkrkdhk
15
woaodkdaoadrwdw
Output
8
-1
10
10
11
-1
-1
9
-1
*/
#include <bits/stdc++.h>
using namespace std;

bool checkValid(map<char, int>& freq) {
    return freq['h'] >= 1 && freq['a'] >= 1 && freq['r'] >= 2 && 
           freq['d'] >= 1 && freq['w'] >= 1 && freq['o'] >= 1 && freq['k'] >= 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        map<char, int> freq;
        int ans = INT_MAX;
        int left = 0;
        
        // Sliding window approach
        for (int right = 0; right < n; right++) {
            freq[s[right]]++;
            
            // Try to minimize window size
            while (checkValid(freq)) {
                ans = min(ans, right - left + 1);
                freq[s[left]]--;
                left++;
            }
        }
        
        // Check if we found a valid substring
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}
// Time complexity: O(n)
