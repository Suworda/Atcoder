#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[500005];

bool valid(int m){
    bool rst = true;
    for(int i=0; i<m; i++){
        int l = a[i];
        int r = a[n-m+i];

        if(l > r/2) rst = 0;
    }

    return rst;    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);

    int l=0, r=n/2;
    int ans=-1;

    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    cout<<ans<<'\n';

}