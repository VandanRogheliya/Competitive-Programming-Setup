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
}

#define MOD 1000000007

//CODE
/*******************************************************/
ll right(vvi a) {
  vvi dp(a.size(), vi(a[0].size(), 0));
  dp[0][0] = a[0][0];
  for(int i = 1; i < (ll)a.size(); i++) {
    dp[i][0] = a[i][0]&(a[i-1][0]);
  }
  for(int j = 1; j < (ll)a[0].size(); j++) {
    dp[0][j] = a[0][j] & (a[0][j-1]);
  }

  for (int i = 1; i < (ll)a.size(); i++) {
    for (int j = 1; j < (ll)a[0].size(); j++) {
      dp[i][j] = max(dp[i - 1][j] & a[i][j], dp[i][j - 1] & a[i][j]);
    }
  }

  return dp.back().back();
}

ll wrong(vvi a) {
  vvi dp(a.size() + 1, vi(a[0].size() + 1, 0));
  dp[0][1] = a[0][0];

  fo(i, (ll)a.size()) {
    fo(j, (ll)a[0].size()) {
      dp[i + 1][j + 1] = max(dp[i + 1][j] & a[i][j], dp[i][j + 1] & a[i][j]);
    }
  }

  return dp.back().back();
}

void solve() {
  ll n;
  // cin >> n;
  // vvi a = {
  //   {24,20,20},
  //   {16,16,12}
  // };
  vvi a = {
    {6,5,5},
    {4,4,3}
  };

  debug(right(a), wrong(a));
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
