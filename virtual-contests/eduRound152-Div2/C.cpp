#include <algorithm>
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

string operate(ll left, ll right, string original, ll prefix[]){
  string res = original;
  sort(res.begin() + left, res.begin() + right);
  return res;
}

/* string operate(ll left, ll right, string original, ll prefix[]){ */
/*   string res = ""; */
/*   for (int i = 0; i < left; i++) { */
/*     res.push_back(original[i]); */ 
/*   } */
/*   ll val_left, val_right, ones, zeroes; */
/*   if (left == 0){ */
/*     val_left = 0; */
/*   } else { */
/*     val_left = prefix[left]; */
/*   } */
/*   val_right = prefix[right]; */
/*   ones = val_right - val_left; */
/*   zeroes = (right - left + 1) - ones; */
/*   /1* cout << ones << " ones\n"; *1/ */
/*   /1* cout << zeroes << " zeroes\n"; *1/ */
/*   while (zeroes > 0){ */
/*     res.push_back('0'); */
/*     zeroes--; */
/*   } */
/*   while (ones > 0){ */
/*     res.push_back('1'); */
/*     ones--; */
/*   } */
/*   for (int i = right + 1; i < original.size(); i++){ */
/*     res.push_back(original[i]); */
/*   } */
/*   return res; */
/* } */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll string_size, operations, left, right;
    cin >> string_size >> operations;

    string original;
    string current_operation;
    cin >> original;
    set<string> strings;

    /* cout << "original " << original << endl; */

    ll prefix[original.size()];
    ll total = 0;
    char c;
    for (int i = 0; i < original.size(); i++){
      c = original[i]; 
      if (c == '1'){total++;}
      prefix[i] = total;
    }

    while (operations > 0) {
      cin >> left >> right;
      left--;
      /* right--; */
      current_operation = operate(left, right, original, prefix);
      /* cout << current_operation << endl; */
      strings.insert(current_operation);
      operations--;
    }

    o(strings.size());
  }
}
