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

vector<int> vals;
int goal;
map<pair<pair<int, int>, int> , bool> cache;

bool dp(int cur, int left, int right){
  auto key = make_pair( make_pair(cur, left), right);
  if (cache.find(key) != cache.end()){
    return cache[key];
  }
  if (left > right){
    /* cout << "out of bounds " << cur << " " << goal << endl; */
    return cur == goal;
  }
  if ((cur & goal) != goal){
    /* cout << "impossible " << cur << endl; */
    return false;
  }
  if (cur == goal){
    /* cout << "reached" << endl; */
    return true;
  }

  /* cout << "val at idx " << idx << " is " << vals[idx] << endl; */
  /* cout << "try " << cur << " and " << (cur & vals[idx]) << endl; */

  bool res =
    dp(cur, left + 1, right) 
    or dp(cur & vals[left], left + 1, right)
    or dp(cur, left, right - 1)
    or dp(cur & vals[right], left, right - 1);
  cache[key] = res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q, temp;
  cin >> n >> goal >> q;

  for (int i = 0; i < n; i++){
    cin >> temp;
    vals.push_back(temp);
  }

  int l, r;
  bool done = false;
  vector<pair<int, int > > segs;
  for (int i = 0; i < q; i++){
    done = false;
    cin >> l >> r;

    for (auto p: segs){
      if (l >= p.first and r <= p.second){
	cout << "YES" << endl;
	done = true;
	continue;
      }
    }
    if (done) continue;

    if (dp(~0, l-1, r - 1)){
      cout << "YES" << endl;
      segs.push_back(make_pair(l, r));
    }
    else {
      cout << "NO" << endl;
    }
  }
}
