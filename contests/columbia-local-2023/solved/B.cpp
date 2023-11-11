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
  ll grid_size, start_health;
  cin >> grid_size >> start_health;

  ll val;
  vl vals;
  for (int i = 1; i <= grid_size; i++){
    cin >> val;
    vals.push_back(val);
  }

  ll time = 2;
  start_health = start_health - 1 + vals[0];
  if (start_health <= 0){
    cout << "NO";
    return 0;
  }
  ll wait;
  for (int i = 1; i < grid_size; i++){

    if (start_health > grid_size - i){
      break;
    }

    cerr << "pos: " << i << endl;
    start_health--;
    if (vals[i] >= 1){
      cerr << "adding health" << endl;
      wait = (start_health) / 2;
      start_health += time - 1;
      start_health += vals[i];
      cerr << "can wait for " << wait * 2 << endl;
      time += wait * 2;
    }
    cerr << "hp " << start_health << " time " << time << endl;
    if (start_health <= 0 or time <= 0){
      break;
    }
    time++;
    cerr << endl;
  }

  if (start_health != 0){
    cout << "YES";
  }
  else {
    cout << "NO";
  } 
}
