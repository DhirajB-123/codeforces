#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    long long small = 0, big = 0, cur = 0;
    int _vals;
    cin >> _vals;
    string input;
    cin >> input;
    for (char c: input){
      if (c == '<'){cur++;}
      if (c == '>'){cur--;}
      small = min(small, cur);
      big = max(big, cur);
    }
    cout << big - small + 1 << endl;
  }
}
