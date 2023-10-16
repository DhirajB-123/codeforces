#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <unordered_map>
#include <utility>
#include <vector>
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

ll MOD = 998244353;

void update(ll t[], int v, int tl, int tr, int l, int r, int add){
  if (l > r){ return; }
  if (l == tl && r == tr){
    t[v] = (t[v] + add) % MOD;
  } else {
    int tm = (tl + tr) / 2;
    update(t, v*2, tl, tm, l, min(r, tm), add);
    update(t, v*2+1, tm+1, tr, max(l, tm+1), r, add);
  }
}

ll sum(ll t[], int v, int tl, int tr, int l, int r){
  if (l > r){
    return 0;
  }
  if (l == tl and r == tr){
    return t[v];
  }
  int tm = (tl + tr) / 2;
  int cur = (t[v] * (r - l + 1)) % MOD;
  return (cur + sum(t, v*2, tl, tm, l, min(r,tm)) + sum(t, v*2+1, tm+1, tr, max(l, tm+1), r)) % MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, q;
  cin >> n >> q;
  ll trees[400000] = {0};
  string q_type;
  ll t1, t2, t3;

  vector<pair<ll, ll> > queries;
  ll left, right;
  ll res;

  for (int i = 0; i < q; i++){
    cin >> q_type;
    if (q_type == "ADD"){
      queries.clear();
      cout << "add here" << endl;
      for (int j = 0; j < n; j++){
	cin >> t1 >> t2;
	queries.push_back(make_pair(t1, t2));
      }
      cin >> t3;
      for (auto query: queries){
	left = query.first;
	right = query.second;
	update(trees, 0, 0, 100000, left, right, t3);
      }
    }
    if (q_type == "SUM") {
      queries.clear();
      cout << "sum here" << endl;
      for (int j = 0; j < n; j++){
	cin >> t1 >> t2;
	queries.push_back(make_pair(t1, t2));
      }
      res = 0;
      for (auto query: queries){
	left = query.first;
	right = query.second;
	res = (res + sum(trees, 0, 0, 100000, left, right)) % MOD;
      }
      cout << res << endl;
    }
  }
}
