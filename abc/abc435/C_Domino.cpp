#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int a[n+4];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    int ans=0;
    for(int l=1, r=1; l<=n; l++){
        if(l <= r) ans++;
        else break;
        r = max(r, l+a[l]-1);
    }

    cout<<ans<<'\n';

}