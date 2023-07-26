#include <bits/stdc++.h>
#include <ios>
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

ll check(vl paintings, ll goal, ll possible){
  if (possible > LLONG_MAX / 2) return 1;
  ll bonus = 2 * possible;
  ll sum = 0;
  ll add;
  // Adding values, multiplying values, summing
  for (long long size: paintings){
    if (size > LLONG_MAX - bonus) return 1;
    if ((size + bonus) > LLONG_MAX / (size + bonus))return 1;
    add = (size + bonus) * (size + bonus);
    if (sum > (LLONG_MAX - add)) return 1;
    sum += add;
  }
  if (sum == goal) return 0;
  if (sum > goal) return 1;
  return -1;
}

ll binSearch(vl paintings, ll goal){
  ll lo = 0, high = goal;
  ll mid, cur;
  while (lo + 1 < high){
    mid = lo + ((high - lo) / 2);
    cur = check(paintings, goal, mid);
    if (cur == 0) return mid;
    if (cur == 1) high = mid;
    if (cur == -1) lo = mid;
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll paintings, totalSize;
    cin >> paintings >> totalSize;
    vl sizes;
    ll val;
    while (paintings--){
      cin >> val;
      sizes.pb(val);
    }
    ll res = binSearch(sizes, totalSize);
    cout << res << endl;
  }
}

/* 
 * Thoughts:
 * Overall, I think bin search will work
 * For some reason tho im just struggling with impl
 * cpp is too much of a headache to debug :sob:
 */
