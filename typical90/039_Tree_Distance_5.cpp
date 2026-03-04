#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nxt[100005];
long long ans;

long long dfs(int u, int pa){
    long long cnt = 1;
    for(auto &v: nxt[u]){
        if(v != pa){
            long long rst = dfs(v, u);
            cnt += rst;
            ans += rst * (n-rst);
        }
    }
    return cnt;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    dfs(1, -1);
    cout<<ans<<'\n';
}
