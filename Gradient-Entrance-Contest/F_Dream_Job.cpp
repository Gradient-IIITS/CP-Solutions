#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define quick                  \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define time cerr << (0.1 * clock()) / CLOCKS_PER_SEC << endl;
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll> pl;
#define forn(n) for (ll i = 0; i < ll(n); i++)

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (auto& i : v) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    v.push_back(v[i]);
  }
  ll maxi = 0, curr = 0;
  k = min(k, n);
  forn(k) { curr += v[i]; }
  maxi = curr;
  for (int i = k; i < v.size(); ++i) {
    curr -= v[i - k];
    curr += v[i];
    maxi = max(maxi, curr);
  }
  cout << maxi << '\n';
}

int main() {
  quick;
  // solve();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}