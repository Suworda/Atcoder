#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll pre_sum[300005], suf_sum[300005];

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    ll a[n+1]={};
    ll b[m+1]={};

    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);

    for(int i=1; i<=m; i++) cin>>b[i];
    sort(b+1, b+m+1);

    for(int i=1; i<=m; i++){
        pre_sum[i] = pre_sum[i-1] + b[i];
    }
    for(int i=m; i>=1; i--){
        suf_sum[i] = suf_sum[i+1] + b[i];
        //cout<<suf_sum[i]<<' ';
    }

    int p = 0;
    ll ans=0;
    for(int i=1; i<=n; i++){
        while(p+1 <= m && b[p+1] <= a[i]) p++;
        ans += p*a[i] - pre_sum[p];
        ans += suf_sum[p+1] - (m-p)*a[i];
        ans%=998244353;
        //cout<<p<<' '<<pre_sum[p]<<' '<<suf_sum[p+1]<<' '<<ans<<'\n';

    }

    cout<<ans<<'\n';

}