#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,K;
int a[200005];

bool valid(int mid, int k){
    for(int i=1; i<=n; i++){
        if(a[i] > mid) continue;

        if((mid - a[i])%i == 0) k -= (mid - a[i])/i;
        else k -= (mid - a[i])/i + 1;
        if(k < 0) return false;
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>K;
    for(int i=1; i<=n; i++) cin>>a[i];

    ll l=1, r=4e18;
    ll ans = -1;
    while(l <= r){
        cout<<'\n';
        ll mid = (l+r)/2;
        if(valid(mid,K)){
            ans = mid;
            l = mid+1;

        }else{
            r = mid-1;
        }
    }

    cout<<ans<<'\n';
    
}
