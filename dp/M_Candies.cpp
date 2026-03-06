#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
int n,k;
int a[101];
long long dp[2][100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int j=0; j<=k; j++) dp[0][j] = 1;

    for(int i=1; i<=n; i++){
        dp[i%2][0] = 1;
        for(int j=1; j<=k; j++){
            if(j <= a[i]) dp[i%2][j] = dp[(i-1)%2][j] % M;
            else dp[i%2][j] = (((dp[(i-1)%2][j] - dp[(i-1)%2][j-a[i]-1]) % M) + M) % M;

            dp[i%2][j] = (dp[i%2][j-1] + dp[i%2][j]) % M;
        }
    }
    
    if(k != 0) cout<<((dp[n%2][k] - dp[n%2][k-1])%M + M) % M<<'\n';
    else cout<<dp[n%2][k]%M<<'\n';
    
}
