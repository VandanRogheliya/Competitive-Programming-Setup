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


class ChristmasBatteries {
  int x, y,z,m;
  int help(int i) {
    return (((x*i)%m*i)%m + (y*i)%m + z) % m;
  }

public:
  int mostFun(int b, int n, int x, int y, int z, int m) {
    int ans = 0;
    this->x = x;
    this->y = y;
    this->z = z;
    this->m = m;

    vvl dp(n,vl(b+1));

    rep(i,0,n-1) {
      if (i%5 == 0) {
        ans += help(i);
        if (i) {
          rep(j,0,b) {
            dp[i][j] = dp[i-1][j];
          }
        }
        continue;
      }

      rep(j,0,b) {
        dp[i][j] = dp[i-1][j];
        if (j - (i%5) >= 0) 
          dp[i][j] = max(dp[i][j], dp[i-1][j-(i%5)] + help(i)); 
      }
    }


    return ans + dp.back().back();
  }
};
// BEGIN CUT HERE
// int main() {
//   IO();
//   ChristmasBatteries ___test;
//   // ___test.mostFun(-1);
// }
// END CUT HERE

/*******************************************************/
