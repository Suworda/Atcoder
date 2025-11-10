#include <iostream>
using namespace std;
long long dp[101][100001];

int main(){
    int n,W;
    cin>>n>>W;
    int w,v;
    for(int i=1; i<=n; i++){
        cin>>w>>v;
        for(int j=1; j<=W; j++){
            if(j-w >= 0) dp[i][j]=max(dp[i-1][j] , dp[i-1][j-w] + v);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][W]<<'\n';
}
