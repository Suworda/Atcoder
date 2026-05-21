#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> nxt[100005];
int c[100005];
bitset<100005> ans;
multiset<int> apr;

void dfs(int u, int pa){
    ans[u] = (apr.find(c[u]) == apr.end());
    apr.insert(c[u]);

    for(int v: nxt[u]){
        if(v == pa) continue;
        dfs(v, u);
    }

    apr.erase(apr.find(c[u]));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>c[i];

    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    dfs(1, 0);

    for(int i=1; i<=n; i++) if(ans[i]) cout<<i<<'\n';
    
}
