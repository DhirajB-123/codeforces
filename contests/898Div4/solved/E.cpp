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

bool binsearch(vl &values, ll h, ll maxWater){
  ll used = 0;
  for (int i = 0; i < values.size(); i++){
    if (h - values[i] > 0) used += h - values[i];
    if (used > maxWater) return false;
  }
  /* cout << "total is " << used << endl; */
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll coralSize, maxWater, cur;
    cin >> coralSize >> maxWater;
    vl coral;
    for (int i = 0; i < coralSize; i++){
      cin >> cur;
      coral.push_back(cur);  
    }

    // left is in the green, right is in the red
    ll left = 0, right = 10e9;
    bool status;
    ll mid;
    /* cout << "max is " << maxWater << endl; */
    while (right - left > 1){
      mid = left + ((right - left)/2);
      status = binsearch(coral, mid, maxWater); 
      if (status == true){
	/* cout << "can make with " << mid << endl; */
	left = mid;
      }
      else {
	right = mid;
      }
    }

    o(left);
  }
}
