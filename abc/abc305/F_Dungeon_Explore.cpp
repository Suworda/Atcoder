#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> nxt[105];
bitset<105> vis;
bool found = 0;

void dfs(int u, int pa){
    int k,v;
    if(u != 1){
        cout<<u<<'\n';
        cout.flush();
    }
    if(u == n){
        exit(0);
    }
    
    cin>>k;
    while(k--){
        cin>>v;
        if(!vis[u]) nxt[u].push_back(v);
    }
    vis[u] = 1;

    for(int v: nxt[u]){
        if(vis[v]) continue;
        dfs(v, u); 

    }

    if(pa){
        cout<<pa<<'\n';
        cout.flush();
        cin>>k;
        while(k--){
            cin>>v;
        }
    }
}

signed main(){
    
    cin>>n>>m;
    dfs(1,0);
    
}
