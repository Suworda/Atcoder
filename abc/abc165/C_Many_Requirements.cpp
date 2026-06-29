#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,q;
int a[55], b[55], c[55], d[55];
vector<int> v(1);
ll ans;

void dfs(int id, int x){
    if(id > n){
        int rst = 0;
        for(int i=1; i<=q; i++){
            rst += d[i]*(v[b[i]] - v[a[i]] == c[i]);
        }
        // cout<<'\n';
        ans = max(ans, rst);
        return;
    }
    for(int i=x; i<=m; i++){
        v.push_back(i);
        dfs(id+1, i);
        v.pop_back();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>q;
    for(int i=1; i<=q; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    dfs(1,1);
    
    cout<<ans<<'\n';
}
