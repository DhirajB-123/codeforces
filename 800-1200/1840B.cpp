#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long t;
    cin >> t;
    while (t--){
        long long n, k;
        cin >> n >> k;
        if (k > 32) k = pow(2, 32) - 1;
        else k = pow(2, k);
        cerr << k << endl;
        if (n + 1 <= k) cout << n + 1 << endl;
        else cout << k << endl;
    }
}
