#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int minIndex = 0;
  int maxDiff = a[1] - a[0];
  int iResult = 1, jResult = 2;

  for (int j = 1; j < n; j++) {
    if (a[j] - a[minIndex] > maxDiff) {
      maxDiff = a[j] - a[minIndex];
      iResult = minIndex + 1;
      jResult = j + 1;
    }
    if (a[j] < a[minIndex]) {
      minIndex = j;
    }
  }

  cout << iResult << " " << jResult << endl;
  cout << maxDiff << endl;

  return 0;
}
