#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n;
  long long B;
  cin >> t;
  while (t--) {
    cin >> n >> B;
    vector<long long> cost(n + 1);
    vector<long long> value(n + 1);

    for (int i = 1; i <= n; i++) {
      cin >> cost[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> value[i];
    }

    vector<vector<long long>> dp(n + 1);

    for (int i = 0; i <= n; i++) {
      dp[i].resize(B + 1);
    }

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }

    for (long long i = 0; i <= B; i++) {
      dp[0][i] = 0;
      dp[1][i] = 0;
    }

    for (int i = 2; i <= n; i++) {
      for (long long j = 0; j <= B; j++) {
        if ((cost[i] + cost[i - 1]) <= j) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - cost[i] - cost[i - 1]] +
                                           value[i] + value[i - 1]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    cout << dp[n][B] << "\n";
  }
}