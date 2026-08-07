#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    int x,y,k;
    cin>>x>>y>>k;
    int ans = 0;
    while(1){
        if(x == y){
            cout<<ans<<'\n';
            return;
        }

        if(x < y){
            y /= k;
            ans++;
        }else{
            x /= k;
            ans++;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
}