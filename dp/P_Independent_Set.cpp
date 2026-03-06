#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
int n;
long long dp[100005][2];
vector<int> nxt[100005];

void dfs(int u, int pa){
    dp[u][0] = dp[u][1] = 1;

    for(int &v: nxt[u]){
        if(v == pa) continue;
        dfs(v,u);

        dp[u][1] *= dp[v][0];
        dp[u][1]%=M;

        dp[u][0] *= (dp[v][0] + dp[v][1]);
        dp[u][0]%=M;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }
    
    dfs(1,-1);
    cout<<(dp[1][0] + dp[1][1])%M<<'\n';
}
