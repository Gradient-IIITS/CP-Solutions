#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);
#define aur cin.tie(0);
#define furious cout.tie(0);
#define file                                   \
  freopen("input/input10.txt", "r", stdin);    \
  freopen("output/output10.txt", "w", stdout); \
  freopen("error.txt", "w", stderr);

vector<int> in, out, depth, parent;
vector<vector<int>> adj;

void init(int n) {
  in = out = depth = parent = vector<int>(n);
  adj.resize(n);
}

void dfs(int s, int& time, int lvl = 0) {
  // in[s] = time;
  // depth[s] = lvl;
  // for(auto u : adj[s]){
  //     time++;
  //     dfs(u,time,lvl+1);
  // }
  // out[s] = ++time;

  stack<int> st;
  vector<int> popOrder;
  st.push(s);
  while (!st.empty()) {
    s = st.top();
    st.pop();
    popOrder.emplace_back(s);
    for (auto u : adj[s]) {
      st.push(u);
    }
  }

  for (auto u : popOrder) {
    while (!st.empty() && st.top() != parent[u]) {
      out[st.top()] = ++time;
      --lvl;
      st.pop();
    }
    in[u] = ++time;
    st.push(u);
    depth[u] = ++lvl;
  }

  while (!st.empty()) {
    out[st.top()] = ++time;
    st.pop();
  }
}

int main() {
  fast aur furious
      // file

      clock_t tStart = clock();
  int n, q;
  cin >> n >> q;
  init(n);
  for (int i = 0; i < n; i++) {
    cin >> parent[i];
    parent[i]--;
    if (parent[i] != -1) adj[parent[i]].emplace_back(i);
  }
  int time = 0;
  for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
      dfs(i, time);
      time++;
    }
  }

  // for(int i = 0;i < n;i++){
  //     cout<<in[i]<<" "<<out[i]<<" "<<depth[i]<<"\n";
  // }

  int count = 0;
  int u, v;
  while (q--) {
    cin >> u >> v;
    u--, v--;
    if (in[v] <= in[u] && out[v] >= out[u]) {
      cout << depth[u] - depth[v] << "\n";
      count++;
    } else
      cout << -1 << "\n";
  }
  // printf("count %ds\n", count);
  // printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}