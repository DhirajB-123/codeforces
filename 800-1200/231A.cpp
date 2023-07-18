#include <bits/stdc++.h>
using namespace std;

int main(){
  int lines;
  int a, b, c;
  int total;
  int solved = 0;
  cin >> lines;
  for (int _ = 0; _ < lines; _++){
    cin >> a >> b >> c; 
    total = 0;
    if (a == 1){total++;}
    if (b == 1){total++;}
    if (c == 1){total++;}
    if (total >= 2){solved++;}
  }
  cout << solved;
}
