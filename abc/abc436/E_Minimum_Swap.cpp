#include <bits/stdc++.h>
using namespace std;

int nxt[300005];
bitset<300005> vis;
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int x;
    for(int i=1; i<=n; i++){
        cin>>x;
        nxt[i]=x;
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;

        x=i;
        int cnt=0;
        while(!vis[x]){
            cnt++;
            vis[x] = 1;
            x = nxt[x];
        }
        ans += 1LL*cnt*(cnt-1)/2;
    }

    cout<<ans<<'\n';

}