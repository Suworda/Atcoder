#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct PairHash {
    size_t operator()(const pair<int, ll> &p) const {
        return (p.first) ^ (p.second);
    }
};

int n,x;
vector<int> a;
int ans = 0;
// unordered_map<pair<int,ll>, ll, PairHash> dp;
vector<ll> dp2;

// void check(int x){
//     int cur = x;
//     for(int i=0; i<n; i++) cur %= a[i];
//     if(cur == 0){
//         cout << x << ' ';
//         ans++;
//     }
// }

ll f(int id, int r){
    if(id >= n || r <= 0) return 0;
    ll m = a[id];
    if(r < m){
        auto it = lower_bound(a.begin(), a.end(), r, greater<>());
        int nxt_id = it - a.begin();
        return f(nxt_id, r);
    }
    int cnt = r/m;
    ll x;
    if(dp2[id] != -1) x = dp2[id];
    else x = dp2[id] = f(id+1, m-1);
    ll y = f(id+1, r%m);
    ll rst = cnt + cnt * x + y;
    // cout<<id<<' '<<r<<' '<<cnt<<':'<<cnt*(r/m)<<' '<<rst<<'\n';
    return rst;
}

void sol(){
    ans = 0;
    cin>>n>>x;
    a.clear();
    // dp.clear();
    int last = 2e18;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(num < last){
            a.push_back(num);
            last = num;
        }
    }
    n = a.size();
    dp2.assign(n, -1);
    
    // for(int num: a) cout<<num<<' ';
    // cout<<'\n';

    cout << f(0,x) << '\n';

    // for(int i=1; i<=x; i++){
    //     check(i);
    // }

    // cout<<'\n';
    // cout<<ans<<'\n';
    // // cout<<"\n\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
    
}

/*
17452
17452
17452
17452
6980
3490
*/