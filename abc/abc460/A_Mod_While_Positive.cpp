#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int ans = 0;
    while(m){
        m = n%m;
        ans++;
    }

    cout<<ans<<'\n';
    
}
