#include <iostream>

using namespace std;

const long long mod = 1000000007;
const long long modp = mod - 1;

long long exp(long long a, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p % 2) {
      res = (res * a) % mod;
      p--;
    } else {
      a = (a * a) % mod;
      p /= 2;
    }
  }
  return res;
}

int main() {
  int t, n;
  long long a, k, S;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    S = 1;

    for (int i = 0; i < n; i++) {
      cin >> a;
      S = (S * a) % modp;
    }

    cout << exp(k + 1, S) << "\n";
  }
}