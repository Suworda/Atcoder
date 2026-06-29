#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> nxt[200005];
vector<int> nodes[200005];
int in[200005];
int out[200005];
int id;

void dfs(int u, int dep){
    in[u] = ++id;
    nodes[dep].push_back(id);
    for(int v: nxt[u]){
        dfs(v,dep+1);
    }    
    out[u] = id;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=2; i<=n; i++){
        int p;
        cin>>p;
        nxt[p].push_back(i);
    }

    dfs(1,0);

    int q;
    cin>>q;
    while(q--){
        int u,d;
        cin>>u>>d;
        
        auto it1 = lower_bound(nodes[d].begin(), nodes[d].end(), in[u]);
        auto it2 = upper_bound(nodes[d].begin(), nodes[d].end(), out[u]);

        cout<<(it2 - it1)<<'\n';
    }

    
}
