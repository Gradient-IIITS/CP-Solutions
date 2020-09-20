#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(int n) {
  if (n <= 4) return n;

  vector<ll> bestUse(n + 1);
  for (int i = 0; i <= 4; i++) {
    bestUse[i] = i;
  }

  for (int i = 5; i <= n; i++) {
    ll max_val = 0;
    for (int j = 1; j <= i / 2; j++) {
      max_val = max(max_val, max(bestUse[j] + bestUse[i - j],
                                 bestUse[j] * bestUse[i - j]));
    }
    bestUse[i] = max_val;
  }
  return bestUse[n];
}

int main(int argc, char *argv[]) {
  int x;
  cin >> x;
  cout << solve(x) << '\n';
}