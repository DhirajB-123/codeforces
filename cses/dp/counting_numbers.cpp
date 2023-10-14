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

vector<ll> num;
// dp[digit][prev_digit][over][started]
ll dp[20][11][2][2];
ll a, b, total_digits;

ll rec(ll pos, ll prev, ll tight, ll started){
  if (pos == num.size()){
    return 1;
  }
  // check cache manually
  if (dp[pos][prev][tight][started] != -1){
    return dp[pos][prev][tight][started];
  }

  ll res = 0;
  ll bound = 9;
  if (tight == 1){
    bound = num[pos];
  }
  for (int digit = 0; digit <= bound; digit++){
    if (digit == prev and started == 1){
      continue;
    }
    ll now_started = started;
    if (digit != 0){
      now_started = true;
    }
    ll new_tight = 0;
    if (digit == bound and tight == 1){
      new_tight = 1;
    }
    res += rec(pos + 1, digit, new_tight, now_started);
  }

  // set cache
  dp[pos][prev][tight][started] = res;
  return res;
};

ll solve(ll b){
  ll val = b;
  num.clear();
  while (b > 0){
    num.push_back(b % 10);
    b /= 10;
  }
  reverse(all(num));
  /* memset(dp, -1, sizeof(dp)); */
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 11; j++){
      for (int k = 0; k < 2; k++){
	for (int l = 0; l < 2; l++){
	  dp[i][j][k][l] = -1;
	}
      }
    }
  }

  ll res = rec(0, 10, 1, 0);

  /* cerr << "res of " << val << " = " << res << endl; */
  return res;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b;
  ll res;
  if (a != 0){
    res = solve(b) - solve(a - 1);
  }
  else {
    res = solve(b);
  }
  cout << res;
  return 0;
}
