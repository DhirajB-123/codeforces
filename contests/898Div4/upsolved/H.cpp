#include <algorithm>
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

bool visited[200001];
ll node;
bool cycle[200001];

bool findCycle(int cur, int backedge, vector<vector<ll> > &adjList){
  if (visited[cur]){
    /* cout << cur << " in cycle" << endl; */
    cycle[cur] = true;
    return true;
  }
  visited[cur] = true;
  bool flag = false; 
  for (ll dst: adjList[cur]){
    if (dst == backedge) continue;
    flag = findCycle(dst, cur, adjList);
    if (flag){
      if (cycle[cur] == false){
	/* cout << cur << " in cycle" << endl; */
	cycle[cur] = true;
	return true;
      }
      return false;
    }
  }

  return false;
}

ll findDistCycle(ll cur, ll backedge, vector<vector<ll> > &adjList){
  if (cycle[cur]){
    node = cur;
    return 0;
  } 
  ll dist;
  for (ll dst: adjList[cur]){
    if (dst == backedge) continue;
    dist = findDistCycle(dst, cur, adjList);
    if (dist >= 0){
      return dist + 1;
    }
  }
  return -1;
}

ll findDistEntry(ll cur, ll backedge, vector<vector<ll> > &adjList){
  if (cur == node){
    return 0;
  }
  ll dist;
  ll res = 10e9;
  bool found = false;
  for (ll dst: adjList[cur]){
    if (dst == backedge) continue;
    dist = findDistEntry(dst, cur, adjList);
    if (dist >= 0){
      found = true;
      res = min(res, dist + 1);
      /* return dist + 1; */
    }
  }
  if (found) return res;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll n, cat, mouse;
    cin >> n >> cat >> mouse;

    fill(visited, visited + n + 1, false);
    fill(cycle, n + 1 + cycle, false);

    vector<vector<ll> > adjList(n+1);

    ll a, b;
    for (int i = 0; i < n; i++){
      cin >> a >> b;
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }

    findCycle(1, -1, adjList);

    ll mouseDist = findDistCycle(mouse, -1, adjList);
    ll catDist = findDistEntry(cat, -1, adjList);

    /* cerr << "cat dist " << catDist << endl; */
    /* cerr << "moust dist " << mouseDist << endl; */

    if (mouseDist < catDist){
      o("YES");
    }
    o("NO");
  }
}
