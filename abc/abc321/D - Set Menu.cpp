#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n,m,p;
    cin>>n>>m>>p;
    int a[n+1]={}, b[m+1]={};
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=m; i++){
        cin>>b[i];
    }
    sort(b+1, b+1+m);

    long long sum[m+1]={};
    for(int i=1; i<=m; i++){
        sum[i]=sum[i-1]+b[i];
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        auto it = upper_bound(b+1, b+1+m, p-a[i]);
        it--;
        //cout << sum[it-b]<<' '<<a[i]*(it-b)<<' '<<(b+m - it)*p<<'\n';;
        ans += sum[it - b] + a[i]*(it-b) + (b+m - it)*p;
    }

    cout<<ans<<'\n';
}
