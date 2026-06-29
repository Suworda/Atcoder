#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 200005;
int n,m;
vector<int> nxt[N];
bitset<N> vis;
vector<pair<int,int>> e;

void dfs(int u, int pa){
    if(vis[u]) return;
    vis[u] = 1;
    if(u != 1) e.push_back({pa,u});

    for(auto v: nxt[u]){
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
        nxt[v].push_back(u);
    }

    dfs(1,0);
    
    for(auto [x,y]: e){
        cout<<x<<' '<<y<<'\n';
    }

    e.clear();
    vis.reset();
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(q.size()){
        int u = q.front();
        q.pop();


        for(int v: nxt[u]){
            if(!vis[v]){
                q.push(v);
                e.push_back({v,u});
                vis[v] = 1;
            }
        }
    }

    for(auto [x,y]: e){
        cout<<x<<' '<<y<<'\n';
    }
}
