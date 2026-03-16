#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ll long long

int n;
int a[200005];
int stk[200005];
int top=-1;
ll dp[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    stk[++top] = 0;
    a[0] = 2e9;
    
    ll ans = 0;
    for(int i=1; i<=n; i++){
        while(a[i] > a[stk[top]]){
            top--;
        }
        ans += (i - stk[top])*a[i] - (dp[i-1] - dp[stk[top]]);
        dp[i] = ans;
        cout<<ans+1<<'\n';
        stk[++top] = i;
    }
    
}
