#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

void sol(){
    int n,w;
    cin>>n>>w;
    int c[n+1];
    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    
    
    map<int,ll> rst;
    for(int i=-2*w; i<=w && i<=n; i++){
        int cur = i;
        while(cur <= n){
            if(cur >= 1) rst[i] += c[cur];
            cur += 2*w;
        }
    }
    
    
    ll cur = 0;
    for(int i=-2*w; i<-w; i++){
        cur += rst[i];
        // cout<<rst[i]<<'\n';
    }
    ll ans = cur;

    int l = -2*w, r = -w-1;
    while(r+1 <= n && r+1 <= w){
        // cout<<cur<<'\n';
        cur += rst[r+1];
        cur -= rst[l];
        ans = min(ans, cur);
        l++; r++;
    }
    cout<<ans<<'\n';
    // cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
}
