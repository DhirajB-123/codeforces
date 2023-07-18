#include <bits/stdc++.h>
using namespace std;

int main(){
  int people;
  int response;
  cin >> people;
  for (int _ = 0; _ < people; _++){
    cin >> response;
    if (response == 1){
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
}
