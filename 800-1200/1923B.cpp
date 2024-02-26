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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    r(monster_count);
    r(bullets);

    rv(health, monster_count);
    rv(position, monster_count);

    vector<pair<ll, ll> > dis_health;
    f(i, 0, health.size()){
      dis_health.push_back(make_pair(abs(position[i]), health[i]));
    }

    sort(all(dis_health));

    ll time = 0;
    ll carry = 0;
    bool survived = true;

    for (auto x: dis_health){
      if (carry > x.second){
	carry -= x.second;
	continue;
      }
      x.second -= carry; 
      carry = 0;
      time += (x.second / bullets);
      if (x.second % bullets > 0){
	time++;
	carry = bullets - (x.second % bullets);
      }
      if (time > x.first){
	survived = false;
	break;
      }
    }

    if (survived){
      cout << "YES" << endl;
    }
    else { 
      cout << "NO" << endl;
    }
  }
}
