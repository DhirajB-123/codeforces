#include <bits/stdc++.h>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    int ax, ay, bx, by, cx, cy; 
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int upB = max(0, ax-bx), downB = max(0, bx-ax);
    int leftB = max(0, ay-by), rightB = max(0, by-ay);
    int upC = max(0, ax-cx), downC = max(0, cx-ax);
    int leftC = max(0, ay-cy), rightC = max(0, cy-ay);
    int res = min(upB, upC) + min(downB, downC) + min(leftB, leftC) + min(rightB, rightC) + 1;
    cout << res << endl;
  }
}
