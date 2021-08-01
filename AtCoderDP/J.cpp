#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define parr(a,n) fo(i,n){cout << a[i] << " ";}cout<<"\n"
#define sarr(a,n) fo(i,n)cin >> a[i]
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x //cout << ps(ans, decimal places);
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pi> vpii;
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

int n;
// map<vl, double> dp;

double dp[301][301][301];

double recFun(vi cnt) {
  if (cnt[0] >= n) return 0;
  // if (dp.count(cnt)) return dp[cnt];
  // debug(dp[cnt[1]][cnt[2]][cnt[3]]);
  if (floor(dp[cnt[1]][cnt[2]][cnt[3]]) != 0) return dp[cnt[1]][cnt[2]][cnt[3]];
  double ans = 0;
  double tmp;
  // debug(a);

  for (int i = 1; i < 4; i++) {
    if (!cnt[i]) continue;
    cnt[i]--;
    cnt[i-1]++;
    tmp = recFun(cnt) * (cnt[i]+1);
    ans += tmp;
    cnt[i]++;
    cnt[i-1]--;
  }

  ans += (double)n;
  ans /= ((double)n - cnt[0]);
  // debug(cnt, ans);
  return dp[cnt[1]][cnt[2]][cnt[3]] = ans;
}

void solve() {
  cin >> n;
  memset(dp, 0, sizeof(dp));
  vi a(n); sarr(a,n);
  vi cnt(4);
  for (auto x: a) cnt[x]++;
  cout << ps(recFun(cnt), 15);

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
