#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAX 1000001

vector<int> primes;
vector<bool> is_prime(MAX, true);

void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < MAX; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

ll count_p(int n, int p) {
  ll count = 0;
  while (n) {
    count += n / p;
    n /= p;
  }
  return count;
}

ll solve(int a, int b) {
  ll result = 1;
  for (int p : primes) {
    if (p > b) break;
    ll ep = count_p(b, p) - count_p(a - 1, p);
    result = result * (2 * ep + 1) % mod;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  sieve();

  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << '\n';
  }

  return 0;
}
