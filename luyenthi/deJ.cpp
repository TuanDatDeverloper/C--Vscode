#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int total_beautiful_substrings = 0;
    const int K = 15; 

    for (int i = 0; i < N; ++i) {
        std::unordered_map<char, int> counts_dict;
        std::unordered_map<int, int> counts_freq;
        int unique_letters = 0;

        for (int j = i; j < N; ++j) {
            char c = S[j];
            int old_count = counts_dict[c];
            counts_dict[c] += 1;
            int new_count = counts_dict[c];

            if (old_count > 0) {
                counts_freq[old_count]--;
                if (counts_freq[old_count] == 0) {
                    counts_freq.erase(old_count);
                }
            } else {
                unique_letters += 1;
            }
            counts_freq[new_count]++;

            if (unique_letters > K) {
                break;
            }
            if (counts_freq.size() == 1) {
                total_beautiful_substrings += 1;
            }
        }
    }
    std::cout << total_beautiful_substrings << std::endl;
    return 0;
}
