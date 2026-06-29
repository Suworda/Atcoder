#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
ll d[20][20];
ll ans = 0;
bitset<20> used;
int ban;

void dfs(int u, ll sum){
    if(u > n){
        ans = max(ans, sum);
        return;
    }

    used[u] = 1;
    for(int v1=u+1; v1<=n+1; v1++){
        if(!used[v1] && v1 != ban){
            used[v1] = 1;
            for(int v2=u+1; v2<=n+1; v2++){
                if(!used[v2] && v2 != ban) dfs(v2,sum+d[u][v1]);
            }
            used[v1] = 0;
        }
    }
    used[u] = 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            cin>>d[i][j];
        }
    }
   
    if(n%2 == 0){
        dfs(1,0);

    }else{
        for(int i=1; i<=n; i++){
            ban = i;
            if(1 != ban) dfs(1,0);
            else dfs(2,0);
        }
    }

    cout<<ans<<'\n';

}
