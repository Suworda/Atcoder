#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    ll x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;

    int x = (x1 - x2);
    int y = (y1 - y2);
    int c = r1 + r2;

    // ll dis = x*x + y*y

    if(x*x + y*y <= c*c && sqrt(x*x + y*y) + r2 >= r1 && sqrt(x*x + y*y) + r1 >= r2) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
    
}
