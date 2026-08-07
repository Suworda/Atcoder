#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    int x1, x2;
    cin>>x1>>x2;
    int ty0 = gcd(x1, x2), ty1 = x1, ty2 = x2;
    
    for(int i=2; i<n; i++){
        cerr<<ty0<<' '<<ty1<<' '<<ty2<<'\n';
        int x;
        cin>>x;
        tie(ty0, ty1, ty2) = make_tuple(
            gcd(ty0, x),
            ty0,
            max(gcd(ty1, x), gcd(ty2, x))
        );
    }
    
    cerr<<ty0<<' '<<ty1<<' '<<ty2<<'\n';

    cout<<max(ty1, ty2)<<'\n';
    
}