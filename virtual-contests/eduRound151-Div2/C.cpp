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

ll calc(string s){
  int size = s.size();
  ll score = 0, best = 0, cur;
  while (size > 0){
    size--;
    cur = (s[size] - 'A' + 1);
    if (cur > 1){cur = pow(10, cur-1);}
    if (cur >= best) {
      best = cur;
      score += cur;
    } 
    else { score -= cur;}
  }
  return score;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    string s;
    cin >> s;

    // best with 1 char is E
    if (s.size() == 1){ o(calc("E"));}

    // if there are all Es, no improvements
    if (s.find_first_not_of('E') == string::npos){o(calc(s));}

    ll vals[] = {1, 10, 100, 1000, 10000};
    ll best;
    ll score;
  }
}
