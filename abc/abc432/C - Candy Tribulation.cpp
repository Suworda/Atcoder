#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    int d=y-x;
    long long a[n];

    long long ans=0;
    long long w[n];
    long long min_w=9e18;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ans+=a[i];

        w[i]=a[i]*y;
        min_w=min(min_w, w[i]);
    }

    for(int i=0; i<n; i++){
        if((w[i]-min_w)%d != 0 || (w[i]-min_w)/d > a[i]){
            cout<<-1<<'\n';
            return 0;
        }else{
            ans-=(w[i]-min_w)/d;
        }
    }

    cout<<ans<<'\n';




}

