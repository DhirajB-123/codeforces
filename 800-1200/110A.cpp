#include <bits/stdc++.h>

int main(){
  long long input;
  long long curr_digit;
  long long lucky = 0;
  std::cin >> input;
  while (input > 0){
    curr_digit = input % 10;
    if (curr_digit == 4 or curr_digit == 7){
      lucky += 1;
    }
    input = input / 10;
  }
  if (lucky == 4 or lucky == 7){
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}
