#include <bits/stdc++.h>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    bool left = false, right = false;
    int l, r;
    int n, k;
    cin >> n >> k;
    while (n--){
      cin >> l >> r;
      if ( l == k ) {left = true;}
      if ( r == k ) {right = true;}
    }
    cout << (left and right ? "YES":"NO") << "\n";
  }
}
