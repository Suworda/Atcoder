#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,q;
vector<int> nxt[150005];
int vis[150005][4];
int ans;
int passed[150005];

void dfs(int u, int step, int k, int id){
    if(vis[u][step] == id || step > k) return;

    vis[u][step] = id;
    if(passed[u] != id) ans += u;
    passed[u] = id;
    
    for(int v: nxt[u]){
        dfs(v, step+1, k, id);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }    

    cin>>q;
    for(int i=1; i<=q; i++){
        int x,k;
        cin>>x>>k;
        ans = 0;
        dfs(x,0,k,i);
        cout<<ans<<'\n';
    }
    
}
