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
void nope() {
  cout << "-1\n";
  exit(0);
}
void solve() {
  ll n, m;
  cin >> n >> m;

  vl l(m); sarr(l, m);

  ll sum = 0;

  fo(i, m) sum += l[i];

  if (sum < n) nope();

  vl a(n, 0);

  fo(i, m) {
    if (i + l[i] - 1 >= n) nope();
    a[i] = i + 1;
  }
  for (int i = m - 1; i < m - 1 + l.back(); i++) a[i] = m;
  ll cnt = 0;

  fo(i, n) if (!a[i]) cnt++;

  ll shift = 0;
  // debug(a);

  vl ans;
  fo(i, m) {
    ans.pb(i + 1ll + shift);
    if (cnt) {
      shift += min(cnt, l[i] - 1ll);
      cnt = max(0ll, cnt - l[i] + 1ll);
    }
    // ans.pb(i + 1ll);
    // // if (cnt) {
    // //   shift += min(cnt, l[i] - 1ll);
    // //   cnt = max(0ll, cnt - l[i] + 1ll);
    // // }
  }
  // vl tmp(m,0);
  // for (int i = m-1; i >= 0; i--) {
  //   if (cnt) tmp[i] = min(cnt, )
  // }

  if (cnt) nope();

  parr(ans, m);
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
