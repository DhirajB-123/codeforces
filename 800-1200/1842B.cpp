#include <bits/stdc++.h>
using namespace std;
 
bool canRead(int s1[], int s2[], int s3[], int ss, int fav){
    if (fav == 0){return true;}
    int i1 = 0, i2 = 0, i3 = 0, cur = 0;
    while (i1 < ss){
        if ((s1[i1] | fav) == fav){
            cur = cur | s1[i1];
            i1 += 1;
        } else { break; }
    }
    if (cur == fav){return true;}
    while (i2 < ss){
        if ((s2[i2] | fav) == fav){
            cur = cur | s2[i2];
            i2 += 1;
        } else { break; }
    }
    if (cur == fav){return true;}
    while (i3 < ss){
        if ((s3[i3] | fav) == fav){
            cur = cur | s3[i3];
            i3 += 1;
        } else { break; }
    }
    return (cur == fav);
}
 
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int stackSize, favNumber;
        cin >> stackSize >> favNumber;
        int stack1[stackSize], stack2[stackSize], stack3[stackSize];
        for (int i = 0; i < stackSize; i++){
            cin >> stack1[i];
        }
        for (int i = 0; i < stackSize; i++){
            cin >> stack2[i];
        }
        for (int i = 0; i < stackSize; i++){
            cin >> stack3[i];
        }
        cout << (canRead(stack1, stack2, stack3, stackSize, favNumber) ? "YES" : "NO") << endl;
    }
}
