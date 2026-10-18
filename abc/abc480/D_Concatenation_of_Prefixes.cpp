#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n, q;
int a[100005];
int seg[100005];
int seg_psum[100005];

bool valid(int mid, int k){
    return mid*(mid+1)/2 <= k;
}

ll f(int k){
    ll rst = 0;
    int l = 0, r=n;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid, k)){
            rst = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return rst;
}

ll query(int p){
    int k = f(p);
    return seg_psum[k] + seg[p - k*(k+1)/2];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        seg[i] = seg[i-1] + a[i];
    }

    for(int i=1; i<=n; i++){
        seg_psum[i] = seg_psum[i-1] + seg[i];
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        cout << query(r) - query(l-1) << '\n';
    }

    
    
} 