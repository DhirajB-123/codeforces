#include <bits/stdc++.h>
using namespace std;

int main(){
  string input; 
  int upper = 0;
  cin >> input;
  for (char c : input){
    if (isupper(c)){
      upper += 1; 
    }
  }
  bool Uppercase = (upper > (input.length() / 2));
  for (int i = 0; i < input.length(); i++){
    if (Uppercase){
      input[i] = toupper(input[i]);
    } else {
      input[i] = tolower(input[i]);
    }
  }
  cout << input;
}
