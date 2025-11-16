#include <iostream>
#include <algorithm>
using namespace std;

long long cnt[200001]={}, ans=0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    //sort(a,a+n);

    for(int i=1; i<=200000; i++){
        for(int j=1; j<=200000/i; j++){
            ans+=1LL*cnt[i]*cnt[j]*cnt[i*j];
        }
    }

    cout<<ans<<'\n';

}

