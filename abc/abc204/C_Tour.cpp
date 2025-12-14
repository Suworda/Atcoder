#include <bits/stdc++.h>
using namespace std;

vector<int> edge[2005];
bitset<2005> vis;
long long ans=0;

void bfs(int v){
    vis.reset();
    queue<int> q;
    q.push(v);
    vis[v] = true;
    int rst = 0;

    while(q.size()){
        v = q.front();
        q.pop();

        for(int next: edge[v]){
            if(!vis[next]){
                rst++;
                q.push(next);
                vis[next] = true;
            } 
        }
    }
    ans+=rst;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    ans = n;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        edge[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(edge[i].size()) bfs(i);
    }

    cout<<ans<<'\n';

}