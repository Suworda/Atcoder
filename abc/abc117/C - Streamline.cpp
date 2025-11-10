#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    sort(a,a+m);

    int d[m-1];
    for(int i=0; i<m; i++){
        d[i]=a[i+1]-a[i];
    }
    sort(d,d+m-1);

    long long ans=0;
    for(int i=0; i<m-n; i++){
        ans+=d[i];
    }

    cout<<ans<<'\n';
}

