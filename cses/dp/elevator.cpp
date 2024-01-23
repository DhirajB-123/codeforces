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

map<pair<int, int>, int> cache;

int people, weight_cap;
vl fatties;

int bits_set(int bitmask){
  int res = 0;
  while (bitmask != 0){
    if ((bitmask & 1) == 1) res++;
    bitmask >>= 1;
  }
  return res;
}

int dp(int bitmask, int space_left){
  auto key = make_pair(bitmask, space_left);

  if (cache.find(key) != cache.end()){
    return cache[key];
  }

  if (bits_set(bitmask) == people){return 0;}

  int res = INT_MAX;
  for (int i = 0; i < people; i++){
    if ((bitmask & (1 << i)) != (1 << i)){
      int new_mask = bitmask | (1 << i);
      if (fatties[i] <= space_left){
	res = min(res, dp(new_mask, space_left - fatties[i]));
      }
      else {
	res = 1 + min(res, dp(new_mask, weight_cap - fatties[i]));
      }
    }
  }
  cache[key] = res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> people >> weight_cap;
  int tmp;
  for (int i = 0; i < people; i++){
    cin >> tmp;
    fatties.pb(tmp); 
  }
  
  int res = dp(0, 0);

  cout << res;
}
