#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n, q;
int l[300005], r[300005];
int mil[300005], mir[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=2; i<=n; i++){
        cin>>l[i];
    }
    for(int i=1; i<n; i++){
        cin>>r[i];
    }

    mir[0] = 2e9;
    mil[n+1] = 2e9;
    for(int i=1; i<n; i++){
        mir[i] = min(mir[i-1], r[i]);
    }
    for(int i=n; i>=1; i--){
        mil[i] = min(mil[i+1], l[i]);
        // cout << i << ' ' << mil[i] << '\n';
        // cout <
    }

    while(q--){
        int s, t;
        cin>>s>>t;
        if(s < t){
            ll rst1 = r[s];
            ll rst2 = l[s] + mir[s-1];
            cout << min(rst1, rst2) << '\n';
        }
        else{
            ll rst1 = l[s];
            ll rst2 = r[s] + mil[s+1];
            cout << min(rst1, rst2) << '\n';
        }
    }
    
} 