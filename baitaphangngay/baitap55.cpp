#include <iostream>
#include <vector>

using namespace std;

class Event {
public:
    Event(int l, int r) : l(l - 1), r(r - 1) {}

    void apply(vector<int>& perm) const {
        int left = l, right = r;
        while (left < right) {
            swap(perm[left], perm[right]);
            ++left;
            --right;
        }
    }

private:
    int l, r;
};

class Permutation {
public:
    Permutation(int n, const vector<Event>& events) : perm(n) {
        for (int i = 0; i < n; ++i) {
            perm[i] = i;
        }
        for (const auto& event : events) {
            event.apply(perm);
        }
    }

    const vector<int>& get() const {
        return perm;
    }

private:
    vector<int> perm;
};

class CowHerd {
public:
    CowHerd(int n) : cows(n) {
        for (int i = 0; i < n; ++i) {
            cows[i] = i + 1;
        }
    }

    void applyPermutationCycles(const Permutation& permutation, int d) {
        int n = cows.size();
        vector<int> result(n);
        vector<bool> visited(n, false);
        const vector<int>& perm = permutation.get();

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> cycle;
                int pos = i;
                while (!visited[pos]) {
                    visited[pos] = true;
                    cycle.push_back(pos);
                    pos = perm[pos];
                }

                int cycle_len = cycle.size();
                for (int j = 0; j < cycle_len; ++j) {
                    result[cycle[j]] = cows[cycle[(j + d) % cycle_len]];
                }
            }
        }
        cows = result;
    }

    void print() const {
        for (int cow : cows) {
            cout << cow << " ";
        }
        cout << endl;
    }

private:
    vector<int> cows;
};

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<Event> events;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        events.emplace_back(l, r);
    }

    CowHerd herd(n);
    Permutation permutation(n, events);
    herd.applyPermutationCycles(permutation, d);
    herd.print();

    return 0;
}
