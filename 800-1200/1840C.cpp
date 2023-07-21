#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
  ll t;
  cin >> t;
  while (t--){
    ll length, minDays, maxTemp, left = 0, right = 0, res = 0;
    cin >> length >> minDays >> maxTemp;
    while (right < length){
      int cur;
      cin >> cur;
      if (cur <= maxTemp){
	if (right - left + 2 - minDays > 0) res += right - left + 2 - minDays;
      } else left = right + 1;
      right++;
    }
    cout << res << endl;
  }
}
