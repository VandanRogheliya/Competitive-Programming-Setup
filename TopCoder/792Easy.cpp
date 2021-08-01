#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef priority_queue<ll> mxhpl;
typedef priority_queue<int> mxhpi;
typedef priority_queue<ll, vector<ll>, greater<ll>> mnhpl;
typedef priority_queue<int, vector<int>, greater<int>> mnhpi;

#define rep(i,start,end) for(ll i = start; i <= end; ++i)
#define rrep(i,end,start) for(ll i = end; i >= start; --i)
#define parr(a,n) rep(i,0,n-1){cout << a[i] << " ";}cout<<"\n"
#define sarr(a,n) rep(i,0,n-1)cin >> a[i]
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define mset(a,x) memset(a, x, sizeof(a))
#define ps(x,y) fixed<<setprecision(y)<<x //cout << ps(ans, decimal places);
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

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

// Fast IO
void IO() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
}

#define MOD 1000000007

//CODE
/*******************************************************/
#define MX 100000 

class TwoRobots {
  vector<vector<pair<int, int>>> graph;

  int xy[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
  set<ll> vis;

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

  // Getting path
  vector<int> path(int s, int d, vector<int> p) {
    vector<int> ans;

    for (int v = d; v != s; v = p[v])
      ans.push_back(v);
    ans.push_back(s);

    reverse(ans.begin(), ans.end());

    return ans;
  }

  int toNum(int i, int j, int k, int l) {
    ll ans = i * 4000 + j * 400 + k * 40 + l;
    
    // if (vis.count(ans)) {
    //   debug(ans,i,j,k,l);
    // } else {
    //   vis.insert(ans);
    // }
    
    // if (ans == 15727) {
    //   debug(ans,i,j,k,l);
    // }
    return ans;
  }

public:
  int move(vector <string> plan) {
    int n = plan.size();
    int m = plan[0].size();
    graph.resize(200001, vector<pair<int, int>>());

    ll s, d;

    rep(i, 0, n - 1) {
      rep(j, 0, m - 1) {
        if (plan[i][j] == '#') continue;
        rep(k, 0, n - 1) {
          rep(l, 0, m - 1) {
            if (i == k && j == l) continue;
            if (plan[k][l] == '#') continue;

            if (plan[i][j] == 'A' && plan[k][l] == 'B') s = toNum(i, j, k, l);
            if (plan[i][j] == 'a' && plan[k][l] == 'b') d = toNum(i, j, k, l);

            rep(i1, 0, 3) {
              rep(i2, 0, 3) {
                int row1 = i + xy[i1][0];
                int col1 = j + xy[i1][1];
                int row2 = k + xy[i2][0];
                int col2 = l + xy[i2][1];


                if (row1 < 0 ||
                  col1 < 0 ||
                  row2 < 0 ||
                  col2 < 0 ||
                  row1 >= n ||
                  col1 >= m ||
                  row2 >= n ||
                  col2 >= m) {
                  continue;
                }

                if (plan[row1][col1] == '#' || plan[row2][col2] == '#') continue;
                if (row1 == row2 && col1 == col2) continue;
                if ((i == row2 && j == col2) && (row1 == k && col1 == l)) continue;

                graph[toNum(i, j, k, l)].pb({ toNum(row1,col1,row2,col2),1 });

              }
            }

          }
        }
      }
    }

    vector<int> dist(n), p(n);

    dijkstra2(s, dist, p);

    if (dist[d] == INT_MAX) {
      return -1;
    }

    // debug("TEST");
    return dist[d];

  }
};
// BEGIN CUT HERE
int main() {
  IO();
  ll n = 4;
  vector<string> vs(n);
  rep(i, 0, n - 1) {
    cin >> vs[i];
  }
  // debug(vs);
  TwoRobots ___test;
  cout << ___test.move(vs);

}
// END CUT HERE

/*******************************************************/
