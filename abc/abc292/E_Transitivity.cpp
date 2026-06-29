#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> nxt[2005];
bitset<2005> vis;
int ans;

void dfs(int u, int pa){
    if(vis[u]) return;
    vis[u] = 1;
    if(pa) ans++;

    for(int v: nxt[u]){
        dfs(v,u);

    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        nxt[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        vis.reset();
        dfs(i,0);
    }
    
    cout<<ans-m<<'\n';
}
