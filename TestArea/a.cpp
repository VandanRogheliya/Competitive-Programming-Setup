#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define parr(a,n) fo(i,n){cout << a[i] << " ";}cout<<"\n"
#define sarr(a,n) fo(i,n)cin >> a[i]
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define ps(x,y) fixed<<setprecision(y)<<x //cout << ps(ans, decimal places);
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
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

ll LongestIncreasingSubsequenceLength(vl v)
{
  if (v.size() == 0)
    return 0;

  vl tail(v.size(), 0);
  ll length = 1; // always points empty slot in tail  

  tail[0] = v[0];

  for (int i = 1; i < v.size(); i++) {

    // Do binary search for the element in  
    // the range from begin to begin + length 
    auto b = tail.begin(), e = tail.begin() + length;
    auto it = lower_bound(b, e, v[i]);

    // If not present change the tail element to v[i]  
    if (it == tail.begin() + length)
      tail[length++] = v[i];
    else
      *it = v[i];
  }

  return length;
}

ll n, q;
vl h;



ll longestIncreasing(ll l, ll r) {
  vector<pll> vp;
  // set<ll> st;
  for (int i = l; i <= r; i++) {
    // if (st.count(h[i])) continue;
    // st.insert(h[i]);
    vp.pb({ h[i], (ll)i });
  }

  sort(all(vp));

  vl tmp;

  for (auto p : vp) {
    tmp.pb(p.S);
  }

  // debug(tmp);

  return LongestIncreasingSubsequenceLength(tmp);
}

void solve() {
  cin >> n >> q;
  bool s; cin >> s;

  vl a(n);
  sarr(a, n);

  h = a;
  ll prev = 0;
  fo(i, q) {
    ll l, r, x, y;
    cin >> x >> y;

    l = (x + s * prev - 1) % n;
    // l++;
    r = (y + s * prev - 1) % n;
    // r++;


    if (l > r) swap(l, r);
    // debug(l,r);
    prev = longestIncreasing(l, r);
    cout << prev << "\n";
  }

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
