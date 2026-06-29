#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,int> cnt;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cnt[0] = 1;
    int n;
    cin>>n;

    int a[n+5];
    ll sum[n+5]={};
    // for(int i=0; i<=n; i++){
    //     sum[i] = 0;
    // }


    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(i%2 == 0) a[i] = -a[i];
    }

    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        ans += cnt[sum[i]]++;
    }

    cout<<ans<<'\n';

}
