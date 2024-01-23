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
    /* cerr << "start" << endl; */
    ll max;
    cin >> max;

    rv(vals, max-1);
    set<ll> missing;
    for (int i = 1; i <= max; i++){
      missing.insert(i);
    }

    ll suspect;
    ll found = 0;
    if (vals[0] <= max){
      missing.erase(vals[0]);
    }
    else {
      suspect = vals[0];
      found++;
    }

    bool res = false;

    ll diff;
    for (int i = 1; i < vals.size(); i++){ 
      diff = vals[i] - vals[i-1];
      if (diff > max or (missing.find(diff) == missing.end())){
	/* cerr << "found: " << diff << endl; */
	suspect = diff; 
	found++;
      }
      else {
	missing.erase(diff);
      }
    }

    if (found > 1){
      /* cerr << "2 found" << endl; */
      cout << "NO" << endl;
    }
    else {
      vl need;
      for (auto k: missing){
	  need.pb(k);
      }
      /* pv(need); */
      if (need.size() > 2){	
	/* cerr << "missing a lot" << endl; */
	cout << "NO" << endl;
      }
      else if (need.size() == 1){
	cout << "YES" << endl;
      }
      else {
	diff = need[0] + need[1];
	if (suspect == diff){
	  cout << "YES" << endl;
	}
	else {
	  /* cout << "perp doesnt match" << endl; */
	  cout << "NO" << endl;
	}
      }
    }
  }
}
