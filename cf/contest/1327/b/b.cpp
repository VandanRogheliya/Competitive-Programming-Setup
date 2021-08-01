/*

  Time: 20:34:41
  Date: 13/01/2021

*/

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
  freopen("../../../input.txt", "r", stdin);
#endif
}

#define MOD 1000000007

//CODE
/*******************************************************/
#define MX 100000

ll n, k;

void solve() {
  cin >> n;
  vi king(n,0);
  ll marTo = -1;
  ll notMar = -1;
  rep(i,0,n-1) {
    cin >> k;
    ll p;
    marTo = -1;
    bool mar = false;
    rep(_,0,k-1) {
      cin >> p;p--;
      if (mar) continue;
      if (king[p]) continue;
      else {
        king[p] = 1;
        mar = true;
        marTo = p;
      }
    }
    if (marTo == -1 && notMar == -1) {
      notMar = i+1;
    }
  }

  if (notMar == -1) {
    cout << "OPTIMAL\n";
    return;
  }

  cout << "IMPROVE\n";
  cout << notMar << " ";

  rep(i,0,n-1) {
    if (king[i] == 0) {
      cout << i+1 << "\n";
      return;
    }
  }
  
}

int main() {
  IO();
  int t = 1;

  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}

/*******************************************************/
