#include <algorithm>
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

ll cache[201][201][201];

ll dp(vl &R, vl &G, vl &B, ll r, ll g, ll b){
  // base case
  if ((r == R.size() and g == G.size()) or
      (r == R.size() and b == B.size()) or
      (b == B.size() and g == G.size())) return 0;

  // check cache
  if (cache[r][g][b] != -1){
    return cache[r][g][b];
  }

  ll res = 0;
  ll p1 = 0, p2 = 0, p3 = 0;

  // only try the pair if its possible
  if (r < R.size() and g < G.size()){
    p1 = dp(R, G, B, r + 1, g + 1, b) + (R[r] * G[g]);
  }
  if (r < R.size() and b < B.size()){
    p2 = dp(R, G, B, r + 1, g, b + 1) + (R[r] * B[b]);
  }
  if (b < B.size() and g < G.size()){
    p3 = dp(R, G, B, r, g + 1, b + 1) + (B[b] * G[g]);
  }

  // res is the best outcome
  res = max(res, p1);
  res = max(res, p2);
  res = max(res, p3);
 
  // store res
  cache[r][g][b] = res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cache, -1, sizeof(cache));

  ll Rsticks; cin >> Rsticks;
  ll Gsticks; cin >> Gsticks;
  ll Bsticks; cin >> Bsticks;
  vl R, G, B;
  ll val;
  for (int i = 0; i < Rsticks; i++){
    cin >> val;
    R.pb(val);
  }
  for (int i = 0; i < Gsticks; i++){
    cin >> val;
    G.pb(val);
  }
  for (int i = 0; i < Bsticks; i++){
    cin >> val;
    B.pb(val);
  }
 
  sort(R.rbegin(), R.rend());
  sort(G.rbegin(), G.rend());
  sort(B.rbegin(), B.rend());

  pv(R);
  pv(G);
  pv(B);

  cout << dp(R, G, B, 0, 0, 0) << endl;
}
