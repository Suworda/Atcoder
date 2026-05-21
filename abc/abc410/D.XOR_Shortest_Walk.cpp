#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<pair<int,int>> nxt[1005];
bool vis[1005][1200];
int ans = 2e9;


void dfs(int u, int val){
    if(vis[u][val]) return;
    if(u == n) ans = min(ans, val);
    vis[u][val] = 1;

    for(auto &[v,w]: nxt[u]){
        dfs(v, val^w);
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        nxt[a].push_back({b,w});
    }

    dfs(1,0);

    cout << (ans == 2e9 ? -1 : ans) << '\n';

}