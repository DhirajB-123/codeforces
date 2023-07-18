#include <iostream>
using namespace std;
int main(){
  int watermelon_size;
  cin >> watermelon_size;
  if (watermelon_size > 2 && watermelon_size % 2 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
