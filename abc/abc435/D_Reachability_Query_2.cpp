#include <bits/stdc++.h>
using namespace std;

bitset<300005> vis;
bitset<300005> black;
vector<int> edge[300005];

void dfs(int v){
    black[v]=true;
    vis[v]=true;
    for(int from: edge[v]){
        if(!vis[from]) dfs(from);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int x,y;
    while(m--){
        cin>>x>>y;
        edge[y].push_back(x);
    }
    int q;
    cin>>q;
    while(q--){
        int ty,v;
        cin>>ty>>v;
        if(ty==1){
            if(!vis[v]) dfs(v);

        }else{
            if(black[v]) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

}