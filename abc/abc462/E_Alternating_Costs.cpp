#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int t,a,b,x,y;

void sol(){
    cin>>a>>b>>x>>y;
    x = abs(x);
    y = abs(y);
    int ans = 0;
    if(a < b){
        ans += a*min(x,y)*2;
        if(x > y){
            ans += (x-y+1)/2 * a + (x-y)/2 * b;
            if(3*a-b < 0)  ans += (x-y)/2 * (3*a - b);
            
        }else{
            ans += (y-x+1)/2 * b + (y-x)/2 * a;
            if(3*a-b < 0)  ans += (y-x+1)/2 * (3*a - b);
        }

    }else{
        ans += b*min(x,y)*2;
        if(x > y){
            ans += (x-y+1)/2 * a + (x-y)/2 * b;
            if(3*b-a < 0)  ans += (x-y+1)/2 * (3*b - a);
            
        }else{
            ans += (y-x+1)/2 * b + (y-x)/2 * a;
            if(3*b-a < 0)  ans += (y-x)/2 * (3*b - a);
        }
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t--) sol();    
    
}
