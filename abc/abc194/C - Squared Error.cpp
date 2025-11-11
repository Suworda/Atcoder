#include <iostream>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    long long a[n+1], sum[n+1]={};
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=(n-1)*a[i]*a[i];
        ans-=2*(a[i]*sum[i-1]);
    }

    cout<<ans<<'\n';


}
