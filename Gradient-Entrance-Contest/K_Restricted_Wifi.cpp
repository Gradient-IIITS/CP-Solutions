#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<long long, long long> dfs(vector<vector<int>>& adj, vector<bool>& visited,
                               vector<long long>& value,
                               vector<long long>& vals, int i, long long n,
                               long long S) {
  visited[i] = true;
  long long sm = value[i];
  long long c = 1;
  for (int j = 0; j < adj[i].size(); j++) {
    if (!visited[adj[i][j]]) {
      auto d = dfs(adj, visited, value, vals, adj[i][j], n, S);
      sm += d.second;
      c += d.first;
    }
  }
  if (i != 1) {
    vals[i - 2] = (n - c) * sm + (S - sm) * c;
  }
  return make_pair(c, sm);
}

int main() {
  int t, n, a, b;
  long long S;
  cin >> t;
  while (t--) {
    cin >> n;
    S = 0;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    vector<long long> value(n + 1);
    vector<long long> vals(n - 1);
    vector<long long> eds(n - 1);

    for (int i = 1; i <= n; i++) {
      cin >> value[i];
      S += value[i];
    }

    for (int i = 1; i < n; i++) {
      cin >> a >> b >> eds[i - 1];

      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    sort(eds.begin(), eds.end());

    dfs(adj, visited, value, vals, 1, n, S);

    sort(vals.begin(), vals.end(), greater<long long>());

    long long sum = 0;
    for (int i = 1; i < n; i++) {
      sum += eds[i - 1] * vals[i - 1];
    }

    cout << sum << "\n";
  }
}