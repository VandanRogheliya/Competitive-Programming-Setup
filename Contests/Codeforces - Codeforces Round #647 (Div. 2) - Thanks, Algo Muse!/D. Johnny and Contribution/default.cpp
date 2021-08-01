#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define parr(a,n) fo(i,n){cout << a[i] << " ";}cout<<"\n"
#define sarr(a,n) fo(i,n)cin >> a[i]
#define pb push_back
#define all(a) a.begin(),a.end()
#define ps(x,y) fixed<<setprecision(y)<<x //cout << ps(ans, decimal places);
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long long int ll;
typedef unsigned long long int  ull;

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
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
}

#define MOD 1000000007

//CODE
/*******************************************************/

ll n, m;

void solve() {
  cin >> n >> m;
  vvl gr(n, vl());
  ll u, v;
  while (m--) {
    cin >> u >> v;
    gr[u - 1].pb(v - 1);
    gr[v - 1].pb(u - 1);
  }

  vl a(n); sarr(a, n);

  set<pll> sp;
  // set<ll> nei;
  fo(i, n) {
    sp.insert({ a[i], i });
  }

  vl ans;

  vi vis(n, 0);
  ll node;
  
  node = -1;
  ll mn = INT_MAX;
  unordered_set<ll> us;

  for (auto p : sp) {
    us.clear();
    for (auto x : gr[p.second]) {
      if (a[x] < p.first) us.insert(a[x]);
    }
    
    if (us.size() != p.first - 1) {
      cout << "-1\n";return;
    } 
  }


  while (ans.size() < n) {
    node = -1;
    mn = INT_MAX;
    for (auto p : sp) {
      if (vis[p.second]) continue;
      for (auto x : gr[p.second]) {
        if (vis[x]) continue;
        mn = min(mn, a[x]);
        if (mn <= p.first) break;
      }

      if (mn <= p.first) continue;


      node = p.second;
      break;
    }

    if (node == -1) {
      cout << "-1\n";
      return;
    }

    ans.pb(node + 1);
    vis[node] = 1;
    sp.erase({ a[node], node });
    // nei.clear();

    // for (auto x : gr[node]) {
    //   if (vis[x]) nei.insert(a[x]);
    //   if (a[node] == a[x]) {
    //     cout << "-1\n";
    //     return;
    //   }
    // }
  }

  parr(ans, n);

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
