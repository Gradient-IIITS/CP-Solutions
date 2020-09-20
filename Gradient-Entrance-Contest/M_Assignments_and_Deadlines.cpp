#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100001
#define MXLOG 18

int ar[MAX_SIZE][26];
int level[MAX_SIZE], LCA[MAX_SIZE][MXLOG];
vector<int> adj[MAX_SIZE];

void dfs(int s, int e) {
  LCA[s][0] = e;
  for (int i = 0; i < 26; i++) {
    ar[s][i] += ((s) ? ar[e][i] : 0);
  }
  for (auto u : adj[s]) {
    if (u == e) continue;
    level[u] = level[s] + 1;
    dfs(u, s);
  }
}

void initLCA(int n) {
  for (int j = 1; j < MXLOG; j++) {
    for (int i = 0; i < n; i++) {
      if (LCA[i][j - 1] != -1) {
        LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
      }
    }
  }
}

int getLCA(int a, int b) {
  if (level[a] > level[b]) swap(a, b);
  int d = level[b] - level[a];
  int temp = 0;
  while (d) {
    if (d & 1) b = LCA[b][temp];
    d >>= 1;
    temp++;
  }
  if (a == b) return a;
  for (int j = MXLOG - 1; j >= 0; j--) {
    if (LCA[a][j] != -1 && (LCA[a][j] != LCA[b][j])) {
      a = LCA[a][j], b = LCA[b][j];
    }
  }

  return LCA[a][0];
}

void takeStr(int n) {
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (auto u : s) {
      ar[i][u - 'a']++;
    }
  }
}

void createAdjList(int n) {
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
}

void processQueries(int q) {
  string str;
  int resStrCharCount[26], strCharCount[26], flag, u, v;
  while (q--) {
    cin >> u >> v >> str;
    u--, v--;
    flag = 1;
    memset(strCharCount, 0, sizeof strCharCount);
    for (auto c : str) strCharCount[c - 'a']++;

    int lca = getLCA(u, v);
    int par = LCA[lca][0];
    for (int i = 0; i < 26; i++) {
      resStrCharCount[i] = ar[u][i] + ar[v][i] - ar[lca][i];
      resStrCharCount[i] -= (par != -1) ? ar[par][i] : 0;
      if (resStrCharCount[i] < strCharCount[i]) {
        flag = 0;
        break;
      }
    }
    cout << flag << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // clock_t tStart = clock();
  int n, q;
  cin >> n;
  memset(ar, 0, sizeof ar);
  memset(LCA, -1, sizeof LCA);
  takeStr(n);
  createAdjList(n);
  dfs(0, -1);
  initLCA(n);
  cin >> q;
  processQueries(q);
  // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}