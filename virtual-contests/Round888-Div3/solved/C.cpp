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
    ll count, block_size;
    cin >> count >> block_size;

    rv(colors, count);

    bool res = false;
    ll size = colors.size() - 1;
    ll start = colors[0];
    ll end = colors[size];

    ll pivot = -1;
    ll seen = 0;
    for (int i = 0; i <= size; i++){
      /* cerr << "here " << i << endl; */
       if (colors[i] == start){
	  seen++;
	  if (seen == block_size){
	    pivot = i;
	    break;
	  }
       }
    }

    if (pivot == -1){
      cout << "NO" << endl;
    }
    else {
      seen = 0;
      if (start == end){
	res = true;
      }
      else {
	for (int i = size; i > pivot; i--){
	  /* cerr << "here " << i << endl; */
	  if (colors[i] == end){
	    seen++;
	    if (seen == block_size){
	      res = true;
	    }
	  }
	}
      }

      if (res){
	cout << "YES" << endl;
      }
      else {
	cout << "NO" << endl;
      }
    }
  }
}
