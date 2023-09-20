#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <unordered_map>
#include <tuple>
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

// mark a x,y pair as seen when i come into it
// not when i leave it
set<pair<pair<ll, ll>, string> > seen;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    // resetting set
    seen.clear();

    ll n, m;
    ll curr_i, curr_j, goal_i, goal_j;
    string dir;

    cin >> n >> m;
    cin >> curr_i >> curr_j >> goal_i >> goal_j;
    cin >> dir;

    if (curr_i == goal_i and curr_j == goal_j) o(0);

    // simulate bounces in while loop
    // if i reach a state twice return -1

    ll bounces = 0;
    pair<pair<ll, ll>, string> cur_key;
    bool bounced;
    while (true){
      if (curr_i == goal_i and curr_j == goal_j) break;
      // how do i move the ball wtf
      bounced = false;
      
      if (dir[0] == 'U'){
	if (curr_i > 1){ curr_i--; }
	else {
	  curr_i++;
	  dir[0] = 'D';
	  bounced = true;
	}
      } 
      else if (dir[0] == 'D'){
	if (curr_i < n){ curr_i++; }
	else {
	  curr_i--;
	  dir[0] = 'U';
	  bounced = true;
	}
      }

      if (dir[1] == 'L'){
	if (curr_j > 1){ curr_j--; }
	else {
	  curr_j++;
	  dir[1] = 'R';
	  bounced = true;
	}
      }
      else if (dir[1] == 'R'){
	if (curr_j < m){ curr_j++; }
	else {
	  curr_j--;
	  dir[1] = 'L';
	  bounced = true;
	}
      }

      /* cerr << curr_i << curr_j << dir << endl;; */

      cur_key = make_pair(make_pair(curr_i, curr_j), dir);
      if (seen.find(cur_key) != seen.end()){
	bounces = -1;
	break;
      }
      seen.insert(cur_key);
      if (bounced) bounces++;
    }
    o(bounces);
  }
}
