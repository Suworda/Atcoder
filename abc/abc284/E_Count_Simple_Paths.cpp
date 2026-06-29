#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> nxt[200005];
bitset<200005> vis;
int ans=0;

void dfs(int u){
    if(vis[u]) return;
    ans++;
    if(ans >= 1000000){
        cout<<ans<<'\n';
        exit(0);
    }
    
    vis[u] = 1;
    for(auto v: nxt[u]){
        dfs(v);
    }
    vis[u] = 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }

    dfs(1);

    cout<<ans<<'\n';

}