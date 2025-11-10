#include <iostream>
using namespace std;

#define int long long

long long dp[250005];

signed main(){
    int n;
    cin>>n;
    int w[n+1], h[n+1], b[n+1], v[n+1];
    int W=0;
    long long base=0;
    for(int i=1; i<=n; i++){
        cin>>w[i]>>h[i]>>b[i];
        base+=b[i];
        W+=w[i];
        v[i]=h[i]-b[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=W; j>=0; j--){
            if(j-w[i]*2>=0) dp[j]=max(dp[j] , dp[j-w[i]*2] + v[i]);
            else dp[j]=dp[j];
        }
    }

    cout<<base+dp[W]<<'\n';


}
