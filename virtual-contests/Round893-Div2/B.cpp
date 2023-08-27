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

/*
 * Idea:
 * so we can at most make Petya take 1 less cookie by removing
 * a seller.
 *
 * this only works if the distance between seller b4 and after
 * is less than d. otherwise Petya eats between them anyway.
*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll benches, sellers, distance;
    cin >> benches >> sellers >> distance;
    vl values;
    ll val;

    // eat at start + each seller
    ll most_eaten = 1;
    for (int i = 0; i < sellers; i++){
      cin >> val;
      if (val != 1){most_eaten++;}
      values.push_back(val);
    }
    // do i eat between start and first seller?
    most_eaten += (values[0] - 2) / distance;
    // do i eat between sellers?
    for (int i = 1; i < values.size(); i++){
      most_eaten += (values[i] - values[i-1] - 1) / distance;
    }
    // do i eat between last seller and end?
    most_eaten += (benches - values[values.size()-1] - 1) / distance;

    // now we know the max. if we find any sellers we can rmv:
    // output the max-1 and count
    // else max and 0
    ll count = 0;
    ll would_eat;
    ll eat_after_rmv;
    for (int i = 0; i < values.size(); i++){
      val = values[i];
      would_eat = 1;
      if (i == 0){
	if (val == 1){ continue;}	
	would_eat += 1;
	would_eat += (val - 2) / distance;
	would_eat += (values[i+1] - val - 1)/distance;
	eat_after_rmv = (values[i+1] - 2) / distance;
	eat_after_rmv++;
      }
      else if (i == values.size() - 1){
	would_eat += (val - values[i-1] - 1) / distance;
	would_eat += (benches - val - 1) / distance;
	eat_after_rmv = (benches - values[i-1]) / distance;
      }
      else{
	would_eat += (val - values[i-1] - 1) / distance;
	would_eat += (values[i+1] - val - 1)/distance;
	eat_after_rmv = (values[i+1] - values[i-1] -1)/distance;
      }	
      if (would_eat > eat_after_rmv){
	count++;
	cerr << "eat " << i+1 << endl;
      }
    }


    /* o(most_eaten); */
    if (count > 0){
      cout << most_eaten - 1 << " " << count << endl;
    }
    else {
      cout << most_eaten << " " << count << endl;
    }
  }
}
