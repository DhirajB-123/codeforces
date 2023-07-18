#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    int n, k;
    cin >> n >> k;
    vector <pair<int, int> > valsWithIdx;
    vector <int> actualWeather;
    int res[n];
    for (int i = 0; i < n; i++){
      int val;
      cin >> val;
      valsWithIdx.push_back({val, i});
    }
    for (int i = 0; i < n; i++){
      int val;
      cin >> val;
      actualWeather.push_back(val);
    }
    sort(valsWithIdx.begin(), valsWithIdx.end());
    sort(actualWeather.begin(), actualWeather.end());
    for (int i = 0; i < n; i++){
      res[valsWithIdx[i].second] = actualWeather[i];
    } 
    for (int x: res){ cout << x << " ";}
    cout << endl;
  }
}
