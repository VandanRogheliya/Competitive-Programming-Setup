#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define parr(a,n) fo(i,n){cout << a[i] << " ";}cout<<"\n"
#define sarr(a,n) fo(i,n)cin >> a[i]
#define pb push_back
#define F first
#define S second
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x //cout << ps(ans, decimal places);
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mi;
typedef map<long long, long long> ml;
typedef set<int> si;
typedef set<long long> sl;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef priority_queue<ll> mxhpl;
typedef priority_queue<int> mxhpi;
typedef priority_queue<ll, vector<ll>, greater<ll>> mnhpl;
typedef priority_queue<int, vector<int>, greater<int>> mnhpi;

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
  // freopen("output.txt", "w", stdout);
#endif
}

#define MOD 1000000007

//CODE
/*******************************************************/

vi parent;
vi rankk;

void make_set(int v) {
  parent[v] = v;
  rankk[v] = 0;
}

int find_set(int v) {
  if (parent[v] == v) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);

  if (a != b) {
    if (rankk[a] < rankk[b]) swap(a, b);
    parent[b] = a;
    if (rankk[a] == rankk[b]) rankk[a]++;
  }
}

struct Edge {
  int u, v, weight;
  bool operator<(const Edge& other) {
    return weight > other.weight;
  }
};

int n, d;
vector<Edge> edges;

int maxSpanningTree() {
  int cost = 0;
  parent.resize(n);
  rankk.resize(n);
  for (int i = 0; i < n; i++) make_set(i);

  sort(edges.begin(), edges.end());

  for (auto e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      cost += e.weight;
      union_sets(e.u, e.v);
    }
  }

  return cost;
}


void solve() {
  scanf("%d%d", &n, &d);
  // cin >> n >> d;

  int nodes[n][d];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      scanf("%d", &nodes[i][j]);
      // cin >> nodes[i][j];
    }
  }

  Edge e;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      e.u = i;
      e.v = j;
      e.weight = 0;
      for (int k = 0; k < d; k++) {
        e.weight += abs(nodes[i][k] - nodes[j][k]);
      }
      edges.pb(e);
    }
  }

  // cout << maxSpanningTree();
  printf("%d", maxSpanningTree());

}

int main() {
  IO();

  int t = 1;
  // cin >> t; 
  while (t--) {
    solve();
  }

  return 0;
}

/*******************************************************/
