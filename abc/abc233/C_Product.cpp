#include <bits/stdc++.h>
using namespace std;


int n;
long long x;
vector<long long> v[100005];
long long ans=0;

void dfs(int r, int c, long long cur){
    if(cur > (long long)1e18) return;
    // cout<<r<<' '<<c<<'\n';

    if(r == n-1){
        // if(cur == x) ans++;
        if(cur == x) ans++;
        return;
    }

    for(int i=0; i<v[r+1].size(); i++){
        dfs(r+1, i, cur*v[r+1][i]);
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>x;
    for(int i=0; i<n; i++){
        int l,a;
        cin>>l;
        while(l--){
            cin>>a;
            v[i].push_back(a);
        }
    }

    for(int i=0; i<v[0].size(); i++){
        dfs(0,i,v[0][i]);
    }
    cout<<ans<<'\n';
}
