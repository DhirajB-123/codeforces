#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
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
    ll size, queries, left, right;
    string original;
    set<pl> distinct;
    cin >> size >> queries;
    cin >> original;
  

    ll left_dp[size], right_dp[size];

    // generating left dp
    left_dp[0] = 0;
    for (ll i = 1; i < size; i++){
      if (original[i-1] == '0'){
	left_dp[i] = left_dp[i-1];
      }
      else { left_dp[i] = i; }
    }
      
    // generating right dp
    right_dp[size-1] = size-1;
    for (ll i = size - 2; i >= 0; i--){
      if (original[i+1] == '1'){
	right_dp[i] = right_dp[i+1];
      }
      else { right_dp[i] = i; }
    }

    // print dps
    for (int i = 0; i < size; i++){
      cerr << left_dp[i] << " ";
    }
    cerr << endl;
    for (int i = 0; i < size; i++){
      cerr << right_dp[i] << " ";
    }
    cerr << endl;

    ll pair_l, pair_r;
    while (queries > 0){
      cin >> left >> right;
      queries--;
      left--;
      right--;
      pair_l = left_dp[left];
      pair_r = right_dp[right];
      if (pair_l > pair_r){
	distinct.insert(make_pair(-1,-1));
      } else {
	distinct.insert(make_pair(pair_l, pair_r));
      }
    }

    o(distinct.size());
  }
}
