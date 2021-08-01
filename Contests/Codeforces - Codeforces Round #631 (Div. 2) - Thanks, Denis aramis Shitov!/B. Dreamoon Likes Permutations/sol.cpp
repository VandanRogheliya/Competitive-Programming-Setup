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
bool check(set<ll> st, ll sz) {
  if ((ll)st.size() != sz) return 0;
  ll prev = 0;
  for (auto x : st) {
    if (prev + 1 == x) {
      prev++;
    }
    else {
      return 0;
    }
  }

  return 1;
}

void solve() {
  ll n;
  cin >> n;
  vl a(n); sarr(a, n);

  ll mx = 0;

  fo(i, n) mx = max(mx, a[i]);

  set<ll> st1, st2;

  ll l1 = mx, l2 = n - mx;
  vector<pi> ans;

  fo(i, l1) {
    st1.insert(a[i]);
  }

  for (int i = l1; i < n; i++) {
    st2.insert(a[i]);
  }

  if (check(st1, l1) && check(st2, l2)) ans.pb({ l1, l2 });

  st1.clear();
  st2.clear();

  if (l1 != l2) {


    fo(i, l2) {
      st1.insert(a[i]);
    }

    for (int i = l2; i < n; i++) {
      st2.insert(a[i]);
    }

    if (check(st1, l2) && check(st2, l1)) ans.pb({ l2, l1 });
  }

  cout << ans.size() << "\n";

  for (auto p : ans) {
    cout << p.first << " " << p.second << "\n";
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
