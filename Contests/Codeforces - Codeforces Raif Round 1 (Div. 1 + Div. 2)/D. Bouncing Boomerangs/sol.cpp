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


void solve() {
  ll n;
  cin >> n;
  vl a(n); sarr(a,n);

  vector<pll> rows(n, { -1, -1 }), cols(n, { -1, -1 });

  set<ll, greater<ll>> empR, oneR, filledR;

  fo(i,n)empR.insert(i); 
  ll tmp;
  for (int i = n-1; i >= 0; i--) {
    if (!a[i]) continue;
    else if (a[i] == 1) {
      if (empR.size() == 0) {
        cout << "-1\n";return;
      }

      tmp = *empR.begin();
      empR.erase(tmp);
      oneR.insert(tmp);
      filledR.insert(tmp);
      rows[tmp] = {i, -1};
      cols[i] = {tmp, -1};
    } else if (a[i] == 2) {
      
      if (oneR.size() == 0) {
        cout << "-1\n";
        return;
      }

      tmp = *oneR.begin();
      oneR.erase(tmp);
      rows[tmp].second = i;
      cols[i].first = tmp;
    } else {
      ll tmpR = -1;
      ll tmpC = -1;
      for (auto x: filledR) {
        pll tmpP = rows[x];
        tmpC = (tmpP.second == -1) ? tmpP.first: tmpP.second;
        if (cols[tmpC].second == -1) {
          tmpR = x;
          break;
        }
      }
      if (tmpR == -1 || empR.size() == 0) {
        cout << "-1\n";return;
      }

      tmp = *empR.begin();
      empR.erase(tmp);
      rows[tmp].first = tmpC;
      cols[tmpC].second = tmp;
      rows[tmp].second = i;
      cols[i].first = tmp;

      filledR.erase(tmpR);
      if (oneR.count(tmpR)) oneR.erase(tmpR);
      filledR.insert(tmp);
    }
  }

  // debug(rows);
  vector<pll> ans;
  for (int i = 0; i < n; i++) {
    if (rows[i].first == -1) continue; 
    ans.pb({i+1, rows[i].first + 1});
    if (rows[i].second != -1) ans.pb({i+1, rows[i].second + 1});
  }

  cout << ans.size() << "\n";
  for (auto p: ans) {
    cout << p.first << " " << p.second << "\n";
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
