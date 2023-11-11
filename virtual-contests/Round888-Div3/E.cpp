#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <sstream>
#include <string>
#include <unordered_map>
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

map<ll, vl> adjList;
map<ll, ll> cache;

ll dp(int idx, vector<ll> &costs){
  cerr << "dp at " << idx << endl;
  ll res = costs[idx];
  auto itr = adjList.find(idx);
  if (itr == adjList.end()){
    return res;
  }
  ll alt = 0;
  for (auto i: itr->second){
    if (i == idx){
      return res;
    }
    alt += dp(i, costs);
  } 
  res = min(res, alt);
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    adjList.clear();
    cache.clear();

    ll pots, free;
    cin >> pots >> free;

    rv(vals, pots);
    for (int i = 0; i < free; i++){
      ll tmp;
      cin >> tmp;
      vals[tmp  - 1] = 0;
    }

    cerr << "costs:" << endl;
    pv(vals);

    string inp;
    getline(cin, inp);
    for (int i = 0; i < pots; i++){
      ll tmp;
      getline(cin, inp);
      istringstream ss(inp);
      while ( ss >> tmp ){
	if (tmp == 0) continue;
	adjList[i].pb(tmp - 1);
      }
    }

    cerr << "read!" << endl;
    // solving
    for (auto p: adjList){
      vals[p.first] = dp(p.first, vals);
    } 
    pv(vals);
  }
}
