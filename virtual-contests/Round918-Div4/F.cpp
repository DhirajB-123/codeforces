#include <bits/stdc++.h>
#include <cstring>
#include <ios>
#include <unordered_map>
#include <tuple>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pair<ll, ll> > vll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f(i,l,r) for (ll i = l; i < r; ++i)
#define fd(i,r,l) for (ll i = r; i >= l; --i)
#define r(x) ll x; cin >> x;
#define rd(x) ld x; cin >> x;
#define rs(s) string s; cin >> s;
#define rc(c) char c; cin >> c;
#define rv(a,n) vl a(n); f(i, 0, n) cin >> a[i];
#define rnv(a) r(n); rv(a,n);
#define pv(a) f(i, 0, a.size()) {cout << a[i] << " ";} cout << endl;
#define TC ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests)
#define o(x) {cout<<x<<'\n'; goto _restart;}
#define ov(a) {pv(a) goto _restart;}

// sort by endpoints
// we can get all endpoints from prior ones between start, end
// IF the time it took to get there was <= time from start to there

struct Vertex {
    ll left, right;
    ll sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(ll lb, ll rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            ll t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(ll k, ll x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    ll get_sum(ll lq, ll rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TC {
    ll people;
    cin >> people;

    vector<tuple<ll, ll, ll>> info;
    ll start, end, time;

    f(i,0,people) {
      cin >> start >> end;
      time = end - start;
      info.push_back({time , end, start});
    }
    sort(info.begin(), info.end());

    Vertex seg(-(10e9), 10e9);
    ll total = 0;
    for (auto person: info){
      start = get<2>(person);
      end = get<1>(person);
      total += seg.get_sum(start, end); 
      cerr << start << " " << end << " " << total << endl;
      seg.add(end, 1);
    }

    cout << total << endl;
  }
}
