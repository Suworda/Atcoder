#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<pair<int,int>> nxt[200005];
int sz[200005];
int ans[200005];
int d;

void dfs_sz(int u, int pa){
    sz[u] = 1;
    for(auto [v,w]: nxt[u]){
        if(v == pa) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

void dfs_ans(int u, int pa, int tag){
    ans[u] = tag;
    for(auto [v,w]: nxt[u]){
        if(v == pa) continue;
        if(n - sz[v] < sz[v]){
            dfs_ans(v, u, tag+w);
        }
        else{
            dfs_ans(v, u, tag-w);
            d += w;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin>>a>>b;
        nxt[a].push_back({b,i});
        nxt[b].push_back({a,i});
    }

    dfs_sz(1, 0);

    dfs_ans(1, 0, 0);

    for(int i=1; i<=n; i++) cout << ans[i] + d << ' ';
} 