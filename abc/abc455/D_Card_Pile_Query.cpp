#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;
int d[300005];
int u[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=0; i<q; i++){
        int c,p;
        cin>>c>>p;
        u[p] = c;
        u[d[c]] = 0;
        d[c] = p;
    }

    for(int i=1; i<=n; i++){
        // cout<<u[i]<<' '<<d[i]<<'\n';
        int ans=0;
        if(!d[i]){
            ans = 1;
            int x = i;
            while(u[x]){
                ans++;
                x = u[x];
            }
        }

        cout<<ans<<' ';
    }
    
}
