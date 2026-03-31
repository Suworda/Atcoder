#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> nxt[101];
bitset<101> vis;

void dfs(int u){
    vis[u] = 1;
    for(int v: nxt[u]){
        if(!vis[v]){
            dfs(v);
        } 
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    
    cout<<ans<<'\n';
}
