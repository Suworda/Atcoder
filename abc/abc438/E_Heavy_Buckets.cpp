#include <bits/stdc++.h>
using namespace std;

int nxt[200005][33];
long long sum[200005][33];

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>nxt[i][0];
        sum[i][0] = i;
    }

    for(int i=1; i<32; i++){
        for(int j=1; j<=n; j++){
            nxt[j][i] = nxt[nxt[j][i-1]][i-1];
            sum[j][i] = sum[j][i-1] + sum[nxt[j][i-1]][i-1];
        }
    }

    // cout<<(0 >> 1)<<'\n';

    //cout<<sum[1][1]<<' '<<sum[1][3]<<"\n";

    

    while(q--){
        int t,b;
        long long ans=0;
        cin>>t>>b;
        for(int i=0; i<32; i++){
            if(t & (1 << i)){
                ans += sum[b][i];
                b = nxt[b][i];
            }
        }
        cout<<ans<<'\n';
    }

    

}