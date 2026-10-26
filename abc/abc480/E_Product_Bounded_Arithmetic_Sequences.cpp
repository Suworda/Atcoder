#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int N;

bool valid(int a, int d, int n){
    // return false;
    __int128 rst = 1;
    for(int i=1; i<=n; i++){
        rst *= a;
        a += d;
        if(rst > N) return false;
    }
    return true;
}

ll f(int a, int n){
    int l=1, r=1e9;
    int rst = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(a, mid, n)){
            rst = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return rst;
    // return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    ll ans = 0;
    for(ll a=1; a<=1000000; a++){
        __int128 x = a*a*a;
        for(int i=3; x <= 1e18 && i<=20; i++, x*=a){
            ans += f(a,i);
        }
    }

    cout << ans << '\n';
    
} 