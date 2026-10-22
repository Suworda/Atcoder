#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int dp[10005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    vector<int> a(k);
    for(int &x: a) cin>>x;

    for(int i=1; i<=n; i++){
        for(int x: a){
            if(i - x >= 0) dp[i] = max(dp[i], i - dp[i-x]);
        }
    }
    
    cout << dp[n] << '\n';
} 