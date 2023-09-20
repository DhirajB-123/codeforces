#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <unordered_map>
#include <utility>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pair<ll, ll> > vll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f(i,l,r) for (ll i = l; i < r; ++i)
#define fd(i,r,l) for (ll i = r; i >= l; --i)
#define r(x) ll x; cin >> x;
#define rd(x) ld x; cin >> x;
#define rs(s) string s; cin >> s;
#define rc(c) char c; cin >> c;
#define rv(a,n) vl a(n); f(i, 0, n) cin >> a[i];
#define rnv(a) r(n); rv(a,n);
#define pv(a) f(i, 0, a.size()) {cout << a[i] << " ";} cout << endl;
#define TC ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests)
#define o(x) {cout<<x<<'\n'; goto _restart;}
#define ov(a) {pv(a) goto _restart;}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll count, cur;
    cin >> count;
    vl vals;
    for (int i = 0; i < count; i++){
      cin >> cur;
      vals.pb(cur);
    }
    sort(vals.begin(), vals.end());
    if (vals[0] != 1){
      o("NO");
    }
    if (vals.size() == 1){
      o("YES");
    }

    // make array
    ll maxVal = vals.back() + 1;
    ll dp[count][maxVal];
    
    // setting base cases
    // can make 1 at first idx and second, but nothing else
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int j = 2; j < maxVal; j++){
      dp[0][j] = 0; 
      dp[1][j] = 0; 
    }
    // can make 0 anywhere
    for (int i = 0; i < count; i++){
      dp[i][0] = 1;
    }

    // we can make a value if we could make it at prev idx
    // or if prev idx, we could make j - vals[i]
    for (int i = 2; i < count; i++){
      cur = vals[i-1];
      for (int j = 1; j < maxVal; j++){
	dp[i][j] = dp[i-1][j];
	if (j - cur >= 0 and dp[i-1][j-cur] == 1){
	  dp[i][j] = 1;
	}
      }
    }

    // debugging :skull:
    /* for (int i = 0; i < count; i++){ */
    /*   for (int j = 0; j < maxVal; j++){ */
	/* cout << dp[i][j] << " "; */
    /*   } */
    /*   cout << endl; */
    /* } */

    bool valid = true;
    for (int i = 0; i < vals.size(); i++){
      if (!(dp[i][vals[i]] == 1)){
	/* cerr << i << " " << vals[i] << endl; */
	/* cerr << dp[i][vals[i]] << endl; */
	valid = false;
	break;
      }
    }
    if (valid){ o("YES"); }
    else { o("NO"); }

  }
}
