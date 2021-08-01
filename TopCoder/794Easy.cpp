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

class IslandInALake {
  vector<string> vs;
  int n, m;
  
  void dfs(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0 || vs[i][j] == '#' || vs[i][j] == ',')
      return;
    vs[i][j] = ',';

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    
  }

  bool check(int i, int j) {
    if (
      (vs[i][j+1] != '!' && vs[i][j+1] != '.') ||
      (vs[i][j-1] != '!' && vs[i][j-1] != '.') ||
      (vs[i+1][j] != '!' && vs[i+1][j] != '.') ||
      (vs[i-1][j] != '!' && vs[i-1][j] != '.') ||
      
      (vs[i+1][j+1] != '!' && vs[i+1][j+1] != '.') ||
      (vs[i+1][j-1] != '!' && vs[i+1][j-1] != '.') ||
      (vs[i-1][j+1] != '!' && vs[i-1][j+1] != '.') ||
      (vs[i-1][j-1] != '!' && vs[i-1][j-1] != '.')

      
      ) {
        return false;
      }
    
    return true;
  }

  int getCnt(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0 || vs[i][j] != '!') return 0;
    int ans = 1;
    vs[i][j] = '@';
    ans += getCnt(i+1,j);
    ans += getCnt(i-1,j);
    ans += getCnt(i,j+1);
    ans += getCnt(i,j-1);

    ans += getCnt(i+1,j-1);
    ans += getCnt(i+1,j+1);
    ans += getCnt(i-1,j-1);
    ans += getCnt(i-1,j+1);

    return ans;
  }

public:
  int build(vector <string> country) {
    vs = country;  
    n = vs.size();
    m = vs[0].size();

    dfs(0,0);
    
    rep(i,1,n-2) {
      rep(j,1,m-2) {
        if (vs[i][j] != '.') continue;

        if (check(i,j)) vs[i][j] = '!'; 
      }
    }

    int result = 0;

    rep(i,0,n-1) {
      rep(j,0,m-1) {
        if (vs[i][j] == '!') result = max(result, getCnt(i,j));
      }
    }

    return result;
  }

};


/*******************************************************/
