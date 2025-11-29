#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100005];
vector<int> dp(100005,-1);

int f(int v){
    if(dp[v] != -1) return dp[v];

    int rst=0;
    for(int x: edge[v]){
        rst=max(rst,f(x)+1);
    }

    return dp[v] = rst;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        edge[y].push_back(x);
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans, f(i));
    }

    cout<<ans<<'\n';

}