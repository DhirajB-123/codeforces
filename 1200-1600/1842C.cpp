#include <unordered_map>
#include <vector>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll solve(vector<ll> arr){
  ll size = arr.size();
  if (size == 1) return 0;
  unordered_map<int, ll> best;
  ll prev = 1;
  best[arr[0]] = 0;
  for (int i = 1; i < size; i++){
    ll ball = arr[i];
    ll res = prev + 1;
    if (best.find(ball) != best.end()){
      res = min(res, best[ball]);
    } else best[ball] = res;
    best[ball] = min(best[ball], prev);
    prev = res;
  }

  return size - prev;
}

int main(){
  int t;
  cin >> t;
  while (t--){
    ll vals;
    ll curr;
    cin >> vals;
    vector<ll> arr;
    while (vals--){
      cin >> curr;
      arr.push_back(curr);
    }
    ll res = solve(arr);
    cout << res << endl;
  }
}



/* from collections import defaultdict */

/* def solve(arr): */
/*     best = defaultdict(int) */ 
/*     leastBalls = [10**6 for _ in arr] */
/*     leastBalls[0] = 1 */
/*     best[arr[0]] = 0 */
/*     for idx in range(1, len(arr)): */
/*         ball = arr[idx] */
/*         # do i have a pair? */
/*         # if so do i take it? */
/*         res = leastBalls[idx - 1] + 1 */
/*         if ball in best: */
/*             res = min(res, best[ball]) */
/*         else: best[ball] = res */
/*         leastBalls[idx] = res */
/*         best[ball] = min(best[ball], leastBalls[idx - 1]) */
/*     print(leastBalls) */
/*     print(len(arr) - leastBalls[-1]) */


/* def __main__(): */
/*     cases = int(input()) */
/*     for _ in range(cases): */
/*         input() */
/*         valStr = input() */
/*         vals = valStr.split(' ') */
/*         arr = [] */
/*         for val in vals: */
/*             arr.append(int(val)) */
/*         solve(arr) */

/* if __name__ == "__main__": */
/*     __main__() */
