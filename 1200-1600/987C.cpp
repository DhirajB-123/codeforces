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

ll solve(vl &fonts, vl &prices, int index){
  ll fixed = prices[index];
  ll pivot = fonts[index];
  ll best_before = 1e12;
  ll best_after = 1e12;

  for (int i = 0; i < index; i++){
    if (fonts[i] < pivot){
      best_before = min(best_before, prices[i]);
    }
  }

  for (int i = index + 1; i < fonts.size(); i++){
    if (fonts[i] > pivot){
      best_after = min(best_after, prices[i]);
    }
  }

  return fixed + best_after + best_before;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int values;
  cin >> values;

  vl fonts, prices;
  ll curr;
  for (int i = 0; i < values; i++){
    cin >> curr;
    fonts.pb(curr);
  }
  for (int i = 0; i < values; i++){
    cin >> curr;
    prices.pb(curr);
  }

  ll res = 1e12;

  for (int i = 1; i < values-1; i++){
    res = min(res, solve(fonts, prices, i));
  }

  if (res == 1e12){ res = -1; }
  cout << res << endl;
}
