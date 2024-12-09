#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>> &g, vector<bool> &vis, vector<int> &to) {
  vis[u] = true;

  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v, g, vis, to);
    }
  }

  to.push_back(u);
}

vector<int> top_order(vector<vector<int>> &g) {
  int n = g.size();
  vector<int> to;
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i, g, vis, to);
    }
  }
  reverse(to.begin(), to.end());
  return to;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  auto to = top_order(g);
  vector<int> lp(n);
  for (int i = 0; i < n; ++i) {
    int u = to[i];
    for (auto v : g[u]) {
      lp[v] = max(lp[v], lp[u] + 1);
    }
  }
  if (lp[to[n - 1]] == n - 1) {
    for (auto u : to) {
      cout << u << " ";
    }
    cout << endl;
  } else {
    cout << "back to the lab" << endl;
  }
}
