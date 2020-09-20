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

int MAXN = 2e5 + 5;

void solve() {
  ll n, q;
  cin >> n;
  vector<ll> v(MAXN);
  while (n--) {
    int x, y;
    cin >> x >> y;
    v[x]++;
    v[y]--;
  }
  forn(MAXN) {
    if (i) {
      v[i] += v[i - 1];
    }
  }
  cin >> q;
  while (q--) {
    int s;
    cin >> s;
    cout << v[s] << '\n';
  }
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