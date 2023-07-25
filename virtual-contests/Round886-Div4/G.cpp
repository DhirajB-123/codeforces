#include <bits/stdc++.h>
#include <cstdlib>
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
    unordered_map<ll, ll> horizontal, vertical, diff;
    ll x, y, cdiff;
    ll pairs;
    cin >> pairs;
    ll res = 0;
    while (pairs--){
      cin >> x >> y;

      if (horizontal.find(x) != horizontal.end()){
	res += horizontal[x] * 2;
	horizontal[x] += 1;
      } else horizontal[x] = 1;

      if (vertical.find(y) != vertical.end()){
	res += vertical[y] * 2;
	vertical[y] += 1;
      } else vertical[y] = 1;

      cdiff = abs(x - y);
      if (diff.find(cdiff) != diff.end()){
	res += diff[cdiff] * 2;
	diff[cdiff] += 1;
      } else diff[cdiff] = 1;
      cout << "curr res " << res << endl;
    }
    cout << res << endl;
  }
}

/*
 * Thoughts:
 * my first thought was to look at the diff between the x and y components
 * when theres the same abs(diff), they can form a diagonal line
 *
 * i also realised we have to keep track of how many have a given x or y
 */
