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
    int size, outOfPlace = 0;
    string s;
    cin >> size >> s;
    int left = 0, right = s.size() - 1;
    while (left < right){
      if (s[left] != s[right]){ outOfPlace++; }
      left++;
      right--;
    }
    
    string res;
    for (int i = 0; i <= size; i++){
      // dont have enough flips
      if (i < outOfPlace){ res.push_back('0'); }
      // have too many flips!
      else if (i > size - outOfPlace){ res.push_back('0'); }
      // if its size is odd we can always solve given
      // an amt of flips within the correct range
      // (flip 2n outer vals if even amt of flips)
      // (flip 2n outer vals and the middle val if odd amt of flips)
      else if (size % 2 == 1){ res.push_back('1'); }
      // if its even its also has to meet this condition
      // (flip 2n outer vals if even amt of flips)
      else if ((outOfPlace - i) % 2 == 0){ res.push_back('1'); }
      // we cant solve it :(
      else {res.push_back('0'); }
    }
    o(res);
  }
}
