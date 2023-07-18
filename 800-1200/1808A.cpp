#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    int left, right, res, bestScore = -1;
    cin >> left >> right;
    while (left <= right){
      int cur = left;
      int curDigit, minDigit = 10, maxDigit = -1;
      while (cur > 0){
	curDigit = cur % 10;
	minDigit = min(minDigit, curDigit);
	maxDigit = max(maxDigit, curDigit);
	cur = cur / 10;
      }
      int score = maxDigit - minDigit;
      if (score > bestScore){bestScore = score; res = left;}
      left++;
      if (score == 9){ break;}
    }
    cout << res << endl;
  }
}
