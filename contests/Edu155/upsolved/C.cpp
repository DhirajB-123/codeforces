#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <string>
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
    ll MODULO = 998244353;
    string input;
    cin >> input;

    ll res = 1;
    ll cur = 1;
    int left = 0;
    int right = 0;
    int del = 0;

    while (right < input.size()){
      if (input[right] == input[left]){
	cur = right - left + 1;
      }
      else {
	if (cur > 1){
	  /* cerr << "new window from " << left << " to " << right << endl; */
	  del += cur - 1;
	  res = (res * cur) % MODULO;
	}
	left = right;
	cur = 1;
      }
      right++;
    }
    cur = right - left;
    if (cur > 1){
      del += cur - 1;
      res = (res * cur) % MODULO;
    }

    for (int i = del; i > 1; i--){
      res = (res * i) % MODULO;
    }

    ll least = 1;
    res = max(res, least);
    cout << del << " " << res << endl;
  }
}
