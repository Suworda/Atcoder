#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    int cnt[n+1]={};
    for(int i=0; i<n; i++){
        cin>>x;
        cnt[x]++;
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=(long long)cnt[i]*(cnt[i]-1)/2*(n-cnt[i]);
    }

    cout<<ans<<'\n';
}
