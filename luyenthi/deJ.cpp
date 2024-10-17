#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int result = 0;
    const int MAX_LENGTH = 100;  // Adjust as needed to balance performance and correctness

    for (int i = 0; i < N; ++i) {
        int counts[52] = {0};
        int unique_chars = 0;

        for (int j = i; j < N && (j - i) < MAX_LENGTH; ++j) {
            char c = S[j];
            int idx;
            if (c >= 'A' && c <= 'Z') {
                idx = c - 'A';
            } else {
                idx = c - 'a' + 26;
            }

            if (counts[idx] == 0) unique_chars++;
            counts[idx]++;

            if (unique_chars >= 2) {
                bool all_equal = true;
                int freq = 0;
                for (int k = 0; k < 52; ++k) {
                    if (counts[k] > 0) {
                        if (freq == 0) freq = counts[k];
                        else if (counts[k] != freq) {
                            all_equal = false;
                            break;
                        }
                    }
                }
                if (all_equal) result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}
