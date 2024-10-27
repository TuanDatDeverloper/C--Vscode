#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

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

vector<int> applyEvents(const vector<int>& perm, const vector<Event>& events) {
    vector<int> newPerm = perm;
    for (const auto& event : events) {
        event.apply(newPerm);
    }
    return newPerm;
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = b[a[i]];
    }
    return result;
}

vector<int> power(const vector<int>& perm, long long d) {
    int n = perm.size();
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = i;
    }
    vector<int> base = perm;
    while (d > 0) {
        if (d % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        d /= 2;
    }
    return result;
}

int main() {
    int n, k;
    long long d;
    cin >> n >> k >> d;
    vector<Event> events;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        events.emplace_back(l, r);
    }

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }
    perm = applyEvents(perm, events);
    perm = power(perm, d);

    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cows[perm[i]] = i + 1;
    }

    for (int cow : cows) {
        cout << cow << " ";
    }
    cout << endl;

    return 0;
}
