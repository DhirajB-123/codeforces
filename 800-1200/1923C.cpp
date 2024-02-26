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

void solve(ll left, ll right, vl &psum, vl &nondecreasable){
  ll total_range = psum[right] - psum[left - 1];
  ll cant = nondecreasable[right] - nondecreasable[left - 1];
  ll len_range = right - left + 1;
  if (total_range >= cant && len_range > 1){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    r(count);
    r(queries);
    rv(values, count);

    vl psum;
    vl cant_dec;
    psum.pb(0);
    cant_dec.pb(0);
    ll total = 0;
    ll dec = 0;
    ll cur;
    for (auto v: values){
      if (v == 1){
	dec++;
      }
      cur = v - 1; 
      total += cur; 
      psum.pb(total);
      cant_dec.pb(dec);
    }

    /* pv(psum); */
    /* pv(cant_dec); */

    ll left, right;
    for (int i = 0; i < queries; i++){
      cin >> left >> right; 
      solve(left, right, psum, cant_dec);
    }
  }
}
