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

void factors(ll n, map<int, int> &m){
  ll z = 2;
  while (z * z <= n){
    if (n % z == 0){
      m[z]++;
      n /= z;
    } 
    else{
      z++;
    }
  }

  if (n > 1) m[n]++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll n;
    cin >> n;
    rv(vals, n);

    bool solved = true;
    map<int, int> f;

    for (auto val: vals){
      factors(val, f);
    }

    for (auto x: f){
      /* cout << x.first << " " << x.second << endl; */
      if (x.second % n != 0){
	solved = false;
	break;
      }
    }

    if (solved){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

// 30 50 27 20
// 2 3 5
// 2 5 5
// 3 3 3
// 2 2 5
//
// 2: 4
// 3: 4
// 5: 4

// 100 2 50 10 1
// 2 2 5 5
// 2
// 2 5 5
// 2 5
// 1

// 8 2 4 2
// 2 2 2
// 2
// 2 2
// 2
