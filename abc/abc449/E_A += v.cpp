#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int a[500005];
int b[500005];
int n,m;
int cnt[500005]={};
vector<pair<int,int>> p;
pair<ll,int> X[200005];
int ans[200005];

void add(int x){
    while(x <= m){
        b[x]++;
        x += x & (-x);
    }
}

int rk(int k){
    int pos = 0;
    int cur = 0;
    for(int i=(1<<21); i>=1; i>>=1){
        if(pos + i <= m && cur+b[pos + i] < k){
            cur += b[pos + i];
            pos += i;
        }
    }

    return pos + 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    for(int i=1; i<=m; i++){
        p.push_back({cnt[i],i});
    }
    sort(p.begin(), p.end());
    p.push_back({9e18,-1});

    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>X[i].first;
        X[i].second = i;
    }

    sort(X, X+q);
    ll cur = n;
    int ptr = 0;

    int last = -1;
    for(int i=0; i<q; i++){
        ll x = X[i].first;
        while(ptr < m && cur < x){
            last = cur;
            if(ptr < m-1) cur += (ptr+1) * (p[ptr+1].first - p[ptr].first);
            else cur = 9e18;
            add(p[ptr].second);
            ptr++;
        }

        if(x <= n) ans[X[i].second] = a[x];
        else{
            if((x-last)%(ptr) != 0) ans[X[i].second] = rk((x-last)%(ptr));
            else ans[X[i].second] = rk(ptr);
        }

    }

    for(int i=0; i<q; i++) cout<<ans[i]<<'\n';

}
