#include <bits/stdc++.h>
using namespace std;

int n;
char a[5005][5005];
int b[5005][5005];
int w[5005][5005];
int dp[5005][5005];

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            b[i][j] = b[i][j-1] + (a[i][j] == '#');
        }

        for(int j=n; j>=1; j--){
            w[i][j] = w[i][j+1] + (a[i][j] == '.');
        }

    }

    dp[1][n+1] = b[1][n];
    for(int j=n; j>=1; j--){
         dp[1][j] = min(dp[1][j+1], b[1][j-1] + w[1][j]);
    } 

    for(int i=2; i<=n; i++){
        dp[i][n+1] = dp[i-1][n+1] + b[i][n] + w[i][n+1];
        for(int j=n; j>=1; j--){
            dp[i][j] = min(dp[i][j+1], dp[i-1][j] + b[i][j-1] + w[i][j]);
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n+1; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n][1]<<'\n';
}
