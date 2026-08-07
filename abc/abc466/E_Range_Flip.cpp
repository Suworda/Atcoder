#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
int n,k;
ll a[N], b[N];
vector<ll> dp(N);

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll cur = 0;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
        cur += a[i];
    }

    while(k--){
        ll mx = 0;
        int x = 0;
        for(int i=1; i<=n; i++){
            int d = b[i] - a[i];
            dp[i] = max(0LL, dp[i-1] + d);
            mx = max(mx, dp[i]);
        }
        
        vector<int> v;
        for(int i=1; i<=n; i++){
            int d = b[i] - a[i];
            v.push_back(i);
            if(dp[i-1] + d < 0){
                v.clear();
            }
            dp[i] = max(0LL, dp[i-1] + d);
            if(dp[i] == mx){
                for(int x: v){
                    swap(a[x], b[x]);
                }
                v.clear();
            }
        }
        cur += mx;
        // cout<<mx<<'\n';
    }

    cout<<cur<<'\n';
    
}