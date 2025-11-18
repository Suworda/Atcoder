#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

long long dp[10001][1001];
char c[1001][1001];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h,w;
    cin>>h>>w;

    dp[1][1]=1;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>c[i][j];

            if(i==1 && j==1) continue;

            if(c[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<'\n';
    }

    cout<<dp[h][w]<<'\n';

}
