#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct BIT{
    int n;
    vector<int> b;

    BIT(int _n) : n(_n), b(n+1) {}

    void add(int x, int v){
        while(x <= n){
            b[x] += v;
            x += x & -x;
        }
    }

    int query(int x){
        int rst = 0;
        while(x){
            rst += b[x];
            x -= x & -x;
        }
        return rst;
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }

};

vector<int> get_rank(vector<int> &v){
    int n = v.size();
    vector<int> rst(n);
    
    vector<int> d = v;
    sort(d.begin(), d.end());

    for(int i=0; i<n; i++){
        auto it = lower_bound(d.begin(), d.end(), v[i]);
        rst[i] = it - d.begin() + 1;
    }
    return rst;
}

int count_inv(vector<int> &rks, vector<int> &rkt){
    int n = rks.size();
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++) v.push_back({rks[i], rkt[i]});
    sort(v.begin(), v.end());

    BIT seen(n);

    int rst = 0;
    for(auto [_, x]: v){
        rst += seen.query(x+1, n);
        seen.add(x, +1);
    }

    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> s(n), t(n);
    for(int &x: s) cin>>x;
    for(int &x: t) cin>>x;
    
    auto rks = get_rank(s);
    auto rkt = get_rank(t);

    ll ans = 0;
    for(int i=0; i<n; i++) ans += abs(t[i] - s[i] - rkt[i] + rks[i]);

    ans += count_inv(rks, rkt);

    cout << ans << '\n';
} 