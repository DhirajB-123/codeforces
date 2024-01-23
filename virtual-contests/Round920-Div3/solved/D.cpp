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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll f, s;
    cin >> f >> s;
    rv(a, f);
    sort(all(a));
    rv(b, s);
    sort(all(b));
    ll p1 = 0, p2 = b.size() - 1;

    ll res1 = 0;
    f(i, 0, a.size()){
      // use first
      if (abs(a[i] - b[p1]) > abs(a[i] - b[p2])){
	res1 += abs(a[i] - b[p1]);
	p1++;
      }
      else {
	res1 += abs(a[i] - b[p2]);
	p2--;
      }
    }

    ll res2 = 0;
    p1 = 0;
    p2 = b.size() - 1;
    fd(i, a.size()-1, 0){
      if (abs(a[i] - b[p1]) >= abs(a[i] - b[p2])){
	res2 += abs(a[i] - b[p1]);
	p1++;
      }
      else {
	res2 += abs(a[i] - b[p2]);
	p2--;
      }
      /* cout << res2 << endl; */
    }

    o(max(res1, res2));
  }
}

/*
 * 3 6 7 9 10
 * 2 3 5 9 9 
 *
 * 6 4 4 4 1
 *
 * 8 6 2 3 6
 *max
1
max
5
max
9
max
13
min
 * */
