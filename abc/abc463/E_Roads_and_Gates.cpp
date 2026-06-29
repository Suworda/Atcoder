#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 300005;
int n,m,y;
vector<pair<int,int>> nxt[N];
int x[N];
bitset<N> vis;
int dis[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>y;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        nxt[a].push_back({b,w});
        nxt[b].push_back({a,w});
    }

    for(int i=1; i<=n; i++) cin>>x[i];

    for(int i=1; i<=n; i++){
        nxt[i].push_back({n+1,x[i]});
        nxt[n+2].push_back({i,x[i]});
    }
    
    nxt[n+1].push_back({n+2, y});

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    while(pq.size()){
        auto [cur, u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        dis[u] = cur;

        for(auto [v,w]: nxt[u]){
            pq.push({cur+w, v});
        }
    }

    for(int i=2; i<=n; i++) cout<<dis[i]<<' ';
    cout<<'\n';


}