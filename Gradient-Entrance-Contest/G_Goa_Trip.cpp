#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long solve(vector<long long> &arr, int m) {
  ll left = 0, right = 0;
  for (ll i : arr) {
    left = max(left, i);
    right += i;
  }
  ll best = right;

  while (left <= right) {
    ll mid = left + (right - left) / 2;
    ll curr = 0;
    ll part = 1;
    bool exceededM = false;
    for (ll i : arr) {
      curr += i;
      if (curr > mid) {
        part += 1;
        curr = i;
      }
    }
    if (part > m) {
      left = mid + 1;
    } else if (part <= m) {
      best = mid;
      right = mid - 1;
    }
  }
  return best;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, k, t, a, b, c, d;

  cin >> n >> m;
  vector<long long> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  long long ans = solve(A, m);
  cout << ans << endl;
}