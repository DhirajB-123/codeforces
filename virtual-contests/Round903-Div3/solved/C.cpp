#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <unordered_map>
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
    ll n;
    cin >> n;

    char vals[n][n];
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
	cin >> vals[i][j];
      }
    }

    vl comp;
    ll highest;
    ll cur;
    ll res = 0;
    ll end = n - 1;
    for (int i = 0; i < n / 2; i++){
      for (int j = 0; j < n / 2; j++){
	highest = 0;
	comp.clear();

	cur = vals[i][j] - 'a';
	/* cout << cur << endl; */
	highest = max(highest, cur);
	comp.pb(cur);

	cur = vals[end - j][i] - 'a';
	/* cout << cur << endl; */
	highest = max(highest, cur);
	comp.pb(cur);

	cur = vals[j][end - i] - 'a';
	/* cout << cur << endl; */
	highest = max(highest, cur);
	comp.pb(cur);
	
	cur = vals[end - i][end - j] - 'a';
	/* cout << cur << endl; */
	highest = max(highest, cur);
	comp.pb(cur);

	/* cout << highest << endl; */

	for (auto l: comp){
	  res += highest - l;
	}	

	/* cout << endl; */
      }
    }
    o(res);
  }
}
