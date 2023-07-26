#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <unordered_map>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pair<ll, ll>> vll;
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
    // number of cases, value, result
    ll n, val, res = 0;
    cin >> n;

    // the slots to place a trap (all zeroed out)
    ll spots[n + 1];
    memset(spots, 0, sizeof(spots));

    // map of value to count of occurences
    map<ll, ll> occur;

    // reading in values and incrementing occurences
    for (ll curr = 0; curr < n; curr++){
      cin >> val;
      occur[val]++; 
    }

    // for each value in the map, we increment the slots
    for (ll curr = 1; curr <=n; curr++){
      // if this value is not in the map we skip
      if (occur[curr] == 0) {
	continue;
      }

      //we simulate the jumps, incrementing the slot by the amt of frogs
      val = curr;
      while (val <= n){
	spots[val] += occur[curr];	
	res = max(res, spots[val]);
	val += curr;
      }
    }

    o(res);
  }
}

/*
 * Thoughts:
 * my brute force idea is iterating thru each possible placement,
 * check the number of frogs that can reach (using modulo)
 * and return the max
 *
 * runs in |frogs|^2, which would TLE with the constraints
 */
