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

void solve(vector<ll> &prefix, ll total){
  ll l, r, k;
  cin >> l >> r >> k;
  bool k_is_even = k % 2 == 0;
  bool range_size_even = (r - l + 1) % 2 == 0;
  ll range_total;
  if (k_is_even or range_size_even) {
    range_total = 0;
  }
  else { range_total = 1; }
  
  ll query_total = total - (prefix[r] - prefix[l - 1]) + range_total;
  if (query_total % 2 == 1){ cout << "YES" << endl; }
  else { cout << "NO" << endl; }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll values, queries;
    cin >> values >> queries;
    vector<ll> prefix(values+1);
    prefix[0] = 0;

    ll total = 0, val;
    for (int i = 1; i <= values; i++){
      cin >> val;
      total += val;
      prefix[i] = total;
    }

    while (queries > 0){
      solve(prefix, total);
      queries--;
    }
  }
}
