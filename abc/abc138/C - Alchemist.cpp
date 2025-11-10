#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

signed main(){
    int n;
    cin>>n;
    double v[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v,v+n);

    double ans=v[0];
    for(int i=1; i<n; i++){
        ans+=v[i];
        ans/=2;
    }
    cout<<fixed<<setprecision(8)<<ans<<'\n';
}
