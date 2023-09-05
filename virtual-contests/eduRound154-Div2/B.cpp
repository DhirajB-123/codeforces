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
    string s1, s2;
    cin >> s1 >> s2;
    bool left[s1.size()], right[s1.size()];
    for (int i = 0; i < s1.size(); i++){

      if (s1[i] == '0' and s2[i] == '0'){
	left[i] = true;
      }
      else {
	left[i] = false;
      }

      if (s1[i] == '1' and s2[i] == '1'){
	right[i] = true;
      }
      else {
	right[i] = false;
      }
    }

    for (int i = 0; i+1 < s1.size(); i++){
      if (left[i] and right[i+1]){
	o("YES");
      }
    }
    o("NO");
  }
}
