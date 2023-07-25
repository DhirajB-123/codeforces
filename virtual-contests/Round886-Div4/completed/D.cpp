#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pair<ll, ll>> vll;
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
    ll n, k;
    cin >> n >> k;
    ll val;
    vl probs;
    /* if (n == 1){ cout << "one prob" << endl; continue;} */
    while (n--){
      cin >> val;
      probs.pb(val);
    }
    sort(all(probs));
    /* pv(probs); */

    ll bestStreak = 0;
    ll currStreak = 1;
    f(i, 1, probs.size()){
      if (probs[i] - probs[i-1] > k){currStreak = 1;}
      else currStreak++;
      bestStreak = max(bestStreak, currStreak);
    }
    if (probs.size() == 1)cout << 0 << endl;
    else cout << probs.size() - bestStreak << endl;
  }
}
