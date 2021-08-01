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
#else
#define timeStart()
#endif

#ifndef ONLINE_JUDGE
#define timeEnd() printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC)
#else
#define timeEnd()
#endif

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

#define MOD 1000000007

//CODE
/*******************************************************/

ll a, b;

void solve() {
  cin >> a >> b;
  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  if (a < b) swap(a, b);

  if (a % b) {
    cout << -1 << "\n";
    return;
  }
  ll tmp = a / b;

  if (setbits(tmp) > 1) {
    cout << -1 << "\n";
    return;
  }
  ll cnt = 0;
  ll div = 8;
  while (tmp != 1) {
    while (tmp % div) {
      div -= 2;
      if (!div) break;
    }
    if (!div) break;
    cnt++;
    tmp /= div;
  }

  if (tmp == 1) cout << cnt << "\n";
  else cout << "-1\n";
}

int main() {
  // IO();

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }


  return 0;
}

/*******************************************************/