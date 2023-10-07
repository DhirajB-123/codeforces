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

void reverse(string &s, vl &occur, int left, int right){
  char tmp;
  int total = 0;
  while (left < right){
    total += occur[left];
    total += occur[right];
    if (total > 0 and total % 2 == 1){
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
    }
    left++;
    right--;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {  
    ll sSize, arrSize;
    cin >> sSize >> arrSize;

    string s;
    cin >> s;

    vl arrSmall, arrBig;
    vl prefix(sSize+1, 0);
    ll cur;
    for (int i = 0; i < arrSize; i++){
      cin >> cur;
      arrSmall.pb(cur);
    }
    for (int i = 0; i < arrSize; i++){
      cin >> cur;
      arrBig.pb(cur);
    }

    ll queries; cin >> queries;
    ll q;
    for (int i = 0; i < queries; i++){
      cin >> q;
      prefix[q-1]++;
    }

    for (int i = 0; i < arrSize; i++){
      reverse(s, prefix, arrSmall[i]-1, arrBig[i]-1);    
    }

    o(s);
  }
}
