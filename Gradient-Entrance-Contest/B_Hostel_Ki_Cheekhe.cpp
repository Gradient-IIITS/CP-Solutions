#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define MOD \
  1000000007  // Constant (prime number) used in most competitive programming
              // problems to reduce the answer to a 32-bit integer.
#define PI \
  3.141592653589793  // Number of digits(15) of Pi which JPL uses for
                     // Interplanetary Caculations.

#define sz(a) int((a).size())
#define pb push_back

#define all(c) c.begin(), c.end()
#define tr(c, it) for (typeof(c.begin()) it = c.begin(); it != c.end(); it++)
// ‘present()’ returns whether the element presents in the container with member
// function ‘find()’ (i.e. set/map, etc.)
//  ‘cpresent’ is for vector.
#define present(c, element) (c.find(element) != c.end())
#define cpresent(c, element) (find(all(c), element) != c.end())

// problem No
void solve() {
  ll N, Y;
  cin >> N >> Y;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ansCnt = 0;
  ll descendingCnt = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i - 1] - 1)
      descendingCnt++;
    else
      descendingCnt = 0;
    if (A[i] == 1 && descendingCnt >= Y - 1) ansCnt++;
  }
  cout << ansCnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}