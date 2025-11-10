#include <iostream>
using namespace std;
long long dp[100001];

int main(){
    int n,W;
    cin>>n>>W;
    int w,v;
    for(int i=1; i<=n; i++){
        cin>>w>>v;

        for(int j=W; j>=1; j--){
            if(j-w >= 0) dp[j]=max(dp[j] , dp[j-w] + v);
            else dp[j]=dp[j];
        }

    }

    cout<<dp[W]<<'\n';
}
