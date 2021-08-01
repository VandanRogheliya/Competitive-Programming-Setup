#include<bits/stdc++.h>
using namespace std;


// DEBUGGING
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int f = 0; cerr << '{'; for (auto& i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector<vector<pair<int, int>>> g;

void fastBellmanford(int s, vector<int>& d, vector<int>& p) {
  int n = g.size();
  d.assign(n, INT_MAX);
  p.assign(n, -1);
  vector<int> cnt(n);
  vector<bool> inqueue(n, false);
  queue<int> q;

  d[s] = 0;
  q.push(s);
  inqueue[s] = true;

  while (!q.empty()) {
    int v = q.front(); q.pop();
    inqueue[v] = false;

    for (auto edge : g[v]) {
      int to = edge.first;
      int len = edge.second;

      if (d[to] > d[v] + len) {
        d[to] = d[v] + len;
        p[to] = v;

        if (!inqueue[to]) {
          q.push(to);
          inqueue[to] = true;

          // cnt number of times to vertex is relaxed/processed
          cnt[to]++;
          if (cnt[to] > n) {
            cout << "ERROR";
            return; // Negative cycle detected
          }
        } 
      }
    }
  }
}

int main() {
  // IO();

  int n, m, s, t;

  cin >> n >> m >> s >> t;

  g.resize(n, vector<pair<int, int>>());
  int a, b, w;

  while (m--) {
    cin >> a >> b >> w;
    g[a].push_back({ b, w });
    g[b].push_back({ a, w });
  }

  vector<int> d, p;
  fastBellmanford(s, d, p);

  debug(d);

  cout << d[t];



  return 0;
}