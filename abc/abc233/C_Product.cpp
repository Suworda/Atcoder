#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
ll x;
vector<int> a[20];
ll ans;

void dfs(int lv, ll val){
    if(lv == n){
        if(val == x) ans++;
        return;
    }

    for(int d: a[lv+1]){
        if(val <= 1e18/d) dfs(lv+1, val*d);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>x;
    for(int i=1; i<=n; i++){
        int l;
        cin>>l;
        for(int j=1; j<=l; j++){
            int val;
            cin>>val;
            a[i].push_back(val);
        }
    }

    dfs(0,1);

    cout<<ans<<'\n';
    
}
