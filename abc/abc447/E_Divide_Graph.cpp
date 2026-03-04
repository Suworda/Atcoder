#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
long long cost[200005];
const int M = 998244353;
int u[200005], v[200005];
int cnt;
int parent[200005];
int used[200005];

int find_pa(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_pa(parent[x]);
}

void check(int x){
    int pu = find_pa(u[x]);
    int pv = find_pa(v[x]);

    if(pu == pv) used[x] = true;
    else if(cnt > 2){
        used[x] = true;
        parent[pu] = pv;
        cnt--;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cost[1] = 2;
    for(int i=2; i<=200000; i++){
        cost[i] = cost[i-1]*2%M;
    }
    
    cin>>n>>m;
    iota(parent+1, parent+n+1, 1);
    cnt = n;
    for(int i=1; i<=m; i++){
        cin>>u[i]>>v[i];
    }

    for(int i=m; i>=1; i--){
        check(i);
    }

    long long ans=0;
    for(int i=1; i<=m; i++){
        if(!used[i]) ans+=cost[i];
        ans%=M;
    }

    // for(int i=1; i<=n; i++) cout<<cost[i]<<' '<<parent[i]<<'\n';

    cout<<ans<<'\n';
    
}
