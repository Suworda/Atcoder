#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    long long ans = 0;
    for(int i=1, r=1; i<=n; i++){
        while(r <= n-1 && a[i]*2 > a[r+1]) r++;
        ans += n - r;
    }

    cout<<ans<<'\n';
}