#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int diff(int a, int b) {
  if (a < b) {
    return b - a;
  } else {
    return a - b;
  }
}

int main() {
  int t, n;
  int S;
  cin >> t;
  while (t--) {
    cin >> n;
    S = 0;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
      cin >> A[i];
      S += A[i];
    }

    int cur = 0;
    int mn = 100000000;

    for (int i = 0; i < n; i++) {
      cur += A[i];
      mn = min(mn, diff(S - cur, cur));
    }

    cout << mn << "\n";
  }
}