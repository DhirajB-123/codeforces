#include <bits/stdc++.h>
#include <cstring>
#include <ios>
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll treeCount, k, cur;
    cin >> treeCount >> k;

    vl fruits, heights;
    vector<bool> valid;
    for (int i = 0; i < treeCount; i++){
      cin >> cur;
      fruits.push_back(cur);
    }
    for (int i = 0; i < treeCount; i++){
      cin >> cur;
      heights.push_back(cur);
    }

    for (int i = 0; i < treeCount - 1; i++){
      if (heights[i] % heights[i+1] == 0){
	valid.push_back(true);
      }
      else valid.push_back(false);
    }
    valid.push_back(true);

    ll left = 0, right = 0; 
    ll window = 0, res = 0;

    while (right < treeCount){
      window += fruits[right];
      while (left <= right and window > k){
	/* cout << "shrinking window" << endl; */
	window -= fruits[left];
	left++;
      }
      if (right - left + 1 > res){
	res = right - left + 1;
	/* cout << "taking " << left << " and " << right << endl; */
      }
      if (valid[right] == false){
	/* cout << right << " is invalid" << endl; */
	left = right + 1;
	window = 0;
      }
      right++;
    }

    o(res);
  }
}
