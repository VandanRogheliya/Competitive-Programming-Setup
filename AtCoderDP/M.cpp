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
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
}

// Time
#ifndef ONLINE_JUDGE
#define timeStart() clock_t z = clock()
#define timeEnd() printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC)
#else
#define timeStart()
#define timeEnd()
#endif

#define MOD 1000000007

//CODE
/*******************************************************/

ll n,k;

void solve() {
  cin >> n >> k;
  vl a(n+1); fo (i,n) cin >> a[i+1];
  vvl dp(n+1,vl(k+1, 0));

  dp[0][0] = 1;
  fo (i, k) dp[0][i+1] = 0;
    // debug(dp[0][0]);

  vl pSum(k+1);

  for (int i = 1; i <= n; i++) {
    pSum[0] = 1;
    for (int j = 1; j <= k; j++) {
      pSum[j] = (pSum[j-1]+dp[i-1][j])%MOD;  
    }

      // debug(pSum);
    dp[i][0] = 1;
    for (int j = 1; j <= k; j++) {
      ll tmp = (j - a[i] - 1 < 0) ? 0 : pSum[j - a[i] - 1];
      dp[i][j] = (pSum[j] - tmp + MOD) % MOD;


      // dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
      // if (a[i] < j) {
      //   dp[i][j]-= (j-a[i]);
      //   dp[i][j] = max(dp[i][j], 0ll);
      //   if (dp[i][j] == 0) break;
      // }
    }
  }
      // debug(dp,a);


  cout << dp[n][k];
}

int main() {
  IO();
  timeStart();

  int t = 1;
  // cin >> t;
  
  while (t--) {
    solve();
  }

  timeEnd();

  return 0;
}

/*******************************************************/
