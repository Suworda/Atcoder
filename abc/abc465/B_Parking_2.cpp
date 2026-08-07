#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int x,y,l,r,a,b;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>x>>y>>l>>r>>a>>b;
    int ans = 0;
    for(int i=a+1; i<=b; i++){
        if(l < i && i <= r) ans += x;
        else ans += y;
    }

    cout<<ans<<'\n';
    
}