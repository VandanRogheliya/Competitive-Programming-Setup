#include <bits/stdc++.h>
using namespace std;

// Resize them
vector<int> parent, treeSize;

void make_set(int v) { //O(1)
  parent[v] = v;
  treeSize[v] = 1;
}

int find_set(int v) { //Almost O(1)
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) { //Almost O(1)
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (treeSize[a] < treeSize[b])
      swap(a, b);
    parent[b] = a;
    treeSize[a] += treeSize[b];
  }
}

// Testing
int main () {

  int n; // number of elements
  cin >> n;
  parent.resize(n+1);
  treeSize.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    make_set(i);
  }

  vector<pair<int, int>> edges;

  int m; // number of edges
  cin >> m;
  int u,v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    edges.push_back({u,v});
  
    union_sets(u,v);
  }

  for (int i = 1; i <= n; i++) {
    cout << treeSize[parent[i]] << " ";
  }

  return 0;
}