#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int a[3005];
int dp[3005][3005][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j][0] = dp[i][j][1] = 2e18;
        }
    }

    for(int i=1; i<=n; i++){
        dp[i][0][0] = 1;
    }
    dp[1][a[1]][1] = 0;

    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + 1);
            if(j- a[i] >= 0) dp[i][j][1] = min(dp[i-1][j-a[i]][0], dp[i-1][j-a[i]][1]);
        }
    }

    for(int i=1; i<=m; i++){
        int ans = min(dp[n][i][0], dp[n][i][1]);
        cout << (ans < 1e18 ? ans : -1) << '\n';
    }
    
} 