#include <iostream>
using namespace std;

int dp[100105];

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        dp[i]=2e9;
    }
    dp[0]=0;
//    for(int i=0; i<n; i++){
//        for(int j=i+1; j<=i+k; j++){
//            dp[j]=min(dp[j] , dp[i] + abs(a[i]-a[j]));
//            //cout<<j<<'\n';
//        }
//    }

    for(int i=1; i<=k; i++){
        for(int j=0; j<n; j++){
            dp[j+i]=min(dp[j+i] , dp[j] + abs(a[j]-a[j+i]));
        }
    }

    cout<<dp[n-1]<<'\n';
}
