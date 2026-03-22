#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int l, r, d, u;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>l>>r>>d>>u;
    ll ans=0;
    for(int i=l; i<=r; i++){
        int x = abs(i);
        if(x%2 == 0) ans += max(0ll, min(x-1,u) - max(-x+1,d) + 1);
    }
    for(int i=d; i<=u; i++){
        int x = abs(i);
        if(x%2 == 0) ans += max(0ll, min(x,r) - max(-x,l) + 1);
    }
    cout<<ans<<'\n';
}
