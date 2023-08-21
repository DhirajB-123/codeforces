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

struct ComparePairs{

};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll healths, damage;
    cin >> healths >> damage;
    
    ll health;
    vll values_with_idx;
    for (int i = 1; i <= healths; i++){
      cin >> health;
      health = health % damage;
      if (health == 0){ health = damage;}
      health = -health;
      values_with_idx.push_back(make_pair(health, i));
    } 
    sort(values_with_idx.begin(), values_with_idx.end());

    vl res;
    for (pair<ll, ll> v_i: values_with_idx){
      res.push_back(v_i.second); 
    }
    ov(res); 
  }
}
