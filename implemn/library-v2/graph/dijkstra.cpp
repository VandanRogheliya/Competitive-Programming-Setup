#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;

// For sparse graph
void dijkstra2(int s, vector<int>& d, vector<int>& p) {
  int n = graph.size();
  d.assign(n, INT_MAX);
  p.assign(n, -1);

  set<pair<int, int>> q;
  d[s] = 0;
  q.insert({ 0, s });

  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());

    for (auto edge : graph[v]) {
      int to = edge.first;
      int len = edge.second;

      if (d[to] > d[v] + len) {
        q.erase({ d[to], to });
        d[to] = d[v] + len;
        p[to] = v;
        q.insert({ d[to], to });
      }
    }
  }
}


// for dense graphs
// Dijkstra's algorithm given GRAPH is global
void dijkstra(int s, vector<int>& d, vector<int>& p) {
  int INF = INT_MAX;
  int n = graph.size();
  d.assign(n, INF);
  p.assign(n, -1);
  vector<bool> vis(n, false);

  d[s] = 0;

  for (int i = 0; i < n; i++) {
    int v = -1;

    for (int j = 0; j < n; j++) {
      if (!vis[j] && (v == -1 || d[j] < d[v]))
        v = j;
    }

    if (d[v] == INF) break;

    vis[v] = true;
    for (auto edge : graph[v]) {
      int to = edge.first;
      int len = edge.second;

      if (d[to] > d[v] + len) {
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }
}

// Getting path
vector<int> path(int s, int d, vector<int> p) {
  vector<int> ans;

  for (int v = d; v != s; v = p[v])
    ans.push_back(v);
  ans.push_back(s);

  reverse(ans.begin(), ans.end());

  return ans;
}

// Testing
int main() {
  int n, s, des; cin >> n;
  graph.resize(n);
  for (int i = 0; i < n; i++) {
    int tmp, nb; cin >> tmp >> nb;
    while (nb--) {
      int nbr, cost; cin >> nbr >> cost;
      graph[tmp - 1].push_back({ nbr - 1, cost });
    }
  }
  int r; cin >> r;
  while (r--) {
    cin >> s >> des;
    vector<int> d(n), p(n);
    dijkstra2(s - 1, d, p);

    cout << "COST:" << d[des - 1] << " Path: ";

    vector<int> pth = path(s - 1, des - 1, p);

    for (int x : pth) cout << x + 1 << " ";
    cout << "\n";
  }

  return 0;
}


// Input:
// 5
// 1
// 1
// 2 1
// 2
// 3
// 4 2
// 5 10
// 1 1
// 3
// 1
// 4 1
// 4
// 3
// 2 2
// 3 1
// 5 1
// 5
// 2
// 2 3
// 4 1
// 1
// 1 3