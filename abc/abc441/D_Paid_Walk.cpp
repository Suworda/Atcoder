#include <bits/stdc++.h>
using namespace std;

struct V{
    int v, cur, dep;
};

int n,m,l,s,t;
// int dep[200005];
vector<pair<int,int>> nxt[200005];
bitset<200005> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>l>>s>>t;

    for(int i=0; i<m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        nxt[u].push_back({v,c});
    }

    queue<V> q;
    q.push({1,0,0});
    while(q.size()){
        auto [u,cur, dep] = q.front();
        q.pop();
        if(cur >= s && cur <= t && dep == l) ans[u] = 1;

        for(auto &[v, c]: nxt[u]){
            if(dep+1 <= l) q.push({v,cur+c,dep+1});
        } 

    }

    for(int i=1; i<=n; i++){
        if(ans[i]) cout<<i<<' ';
    }
    cout<<'\n';
}
