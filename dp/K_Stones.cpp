#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[105];
bool dp[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    dp[0] = 0;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(i - a[j] >= 0 && dp[i-a[j]] == 0) dp[i] = 1;
        }
        // cout << i << ' ' << dp[i] << '\n';
    }

    cout << (dp[k] ? "First" : "Second") << '\n';
}