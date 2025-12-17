#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n,k;
vector<int> nxt[MAXN];
bitset<MAXN> vis, keep;
int ans;

bool dfs(int v){
    if(nxt[v].size() == 0){
        return keep[v];
    }

    bool rst = keep[v];

    for(int u: nxt[v]){
        if(!vis[u]){
            vis[u] = 1;
            if(dfs(u)){
                rst = true;
                ans++;

            }
        }
    }

    return rst;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    ans = 0;
    int a,b;
    for(int i=1; i<n; i++){
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    int x;
    for(int i=0; i<k; i++){
        cin>>x;
        keep[x] = true;
    }

    vis[x] = 1;
    ans += dfs(x);

    cout<<ans<<'\n';

}