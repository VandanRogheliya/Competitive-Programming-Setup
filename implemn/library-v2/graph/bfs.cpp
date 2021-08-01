#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;  // adjacency list representation
int n; // number of nodes
int s; // source vertex
vector<bool> used(n);
vector<int> d(n), p(n); // distance, parent of a node

void bfs() { // O(n+m)
  queue<int> q;

  q.push(s);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : graph[v]) {
      if (!used[u]) {
        used[u] = true;
        q.push(u);
        d[u] = d[v] + 1;
        p[u] = v;
      }
    }
  }
}

// path from source to u (destination)
vector<int> path(int u) {
  vector<int> path;

  if (used[u]){
    for (int v = u; v != -1; v = p[v])
      path.push_back(v);
    reverse(path.begin(), path.end());
  }

  return path;
}