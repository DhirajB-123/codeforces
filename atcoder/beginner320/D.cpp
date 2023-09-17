#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;

void dfs(ll current, ll x, ll y, set<ll> &visited, vector<tuple<ll, ll> > &sol, map<ll, vector<tuple<ll, ll, ll> > > &adjList){
  // update solution and mark person as visited
  sol.at(current) = make_tuple(x, y);
  visited.insert(current);

  auto neighbors = adjList[current];
  for (auto neighbor: neighbors){
    auto [dest, dx, dy] = neighbor;
    // only dfs people we havent seen yet
    if (visited.find(dest) == visited.end()){
      dfs(dest, x + dx, y + dy, visited, sol, adjList);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll people, hints;
  cin >> people >> hints;

  // form adjList 
  map<ll, vector<tuple <ll, ll, ll> > > adjList;
  ll a, b, x, y;
  if (hints > 0){
    while (hints-- > 0){
      cin >> a >> b >> x >> y; 
      adjList[a-1].push_back(make_tuple(b-1, x, y));
      adjList[b-1].push_back(make_tuple(a-1, -x, -y));
    }
  }

  // create our "sol" array and visited set
  // if a person was not visited, they are unknown
  vector< tuple<ll, ll> > sol(people);
  set<ll> visited;

  // run dfs
  dfs(0, 0, 0, visited, sol, adjList);

  for (int i = 0; i < people; i++){
    // not visited, aka unknown
    if (visited.find(i) == visited.end()){
      cout << "undecidable" << endl; 
    }
    else {
      auto [x, y] = sol[i];
      cout << x << " " << y << endl;
    }
  }
}
