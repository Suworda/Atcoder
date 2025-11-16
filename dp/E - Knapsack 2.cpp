#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> dp(101, vector<long long>(100001,9e17));

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,max_w;
    cin>>n>>max_w;

    dp[0][0]=0;

    int w,v;
    for(int i=1; i<=n; i++){
        cin>>w>>v;
        for(int j=0; j<=100000; j++){

            if(j-v >= 0){
                dp[i][j]=min(dp[i-1][j], dp[i-1][j-v]+w);
                //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    for(int i=100000; i>=0; i--){
        //cout<<dp[n][i]<<'\n';
        if(dp[n][i]<=max_w){
            cout<<i<<'\n';
            return 0;
        }
    }
}

