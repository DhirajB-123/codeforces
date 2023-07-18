#include <bits/stdc++.h>
using namespace std;

int main(){
  long long price, starting, wanted, total_price, borrow;
  cin >> price >> starting >> wanted;
  total_price = (wanted * (wanted + 1))/ 2;
  borrow = price * total_price - starting;
  if (borrow > 0){cout << borrow;}
  else {cout << 0;}
}
