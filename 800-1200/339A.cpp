#include <bits/stdc++.h>
using namespace std;

int main(){
  string input;
  int curr;
  long long one = 0, two = 0, three = 0;
  string output;
  cin >> input;
  for (char ch: input){
    if (ch == '1'){one += 1;}
    if (ch == '2'){two += 1;}
    if (ch == '3'){three += 1;}
  }
  curr = 0;
  while (curr < one){
    output.push_back('1');
    output.push_back('+');
    curr += 1;
  }
  curr = 0;
  while (curr < two){
    output.push_back('2');
    output.push_back('+');
    curr += 1;
  }
  curr = 0;
  while (curr < three){
    output.push_back('3');
    output.push_back('+');
    curr += 1;
  }
  output.pop_back();
  cout << output;
}
