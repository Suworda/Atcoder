#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[300005];
int n,q;
int x,y;

bool valid(int tg){
    auto it2 = upper_bound(a, a+n, tg);
    auto it1 = lower_bound(a, a+n, x);
    return (it2 - it1 + y -1 <= tg - x);
}

void sol(){
    cin>>x>>y;
    ll l=1, r=2e9;
    int ans = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    
    while(q--) sol();
}
