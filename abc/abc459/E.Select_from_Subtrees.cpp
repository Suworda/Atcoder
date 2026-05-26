#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;
int n;
ll c[200005];
int d[200005];
int fact[1000005];
vector<int> nxt[200005];

ll power(int a, int b){
    if(b == 0) return 1;

    ll m = power(a,b/2);
    if(b%2 == 0) return m*m%M;
    else return m*m%M*a%M;
}

ll inv(int x){
    return power(x,M-2);
}

ll C(int a, int b){
    if(a < b || a < 0 || b < 0) return 0;
    ll rst = 1;
    for(int i=a; i>a-b; i--){
        rst*=(i%M);
        rst%=M;
    }
    return rst*inv(fact[b])%M;
}

ll dfs(int u){
    ll rst = 1;
    for(int v: nxt[u]){

        rst *= dfs(v);
        rst %= M;

        c[u] += c[v]-d[v];
    }

    rst *= C(c[u], d[u]);

    // cout<<u<<' '<<c[u]<<' '<<rst%M<<'\n';
    return rst%M;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    fact[0] = 1;
    for(int i=1; i<=1000000; i++) fact[i] = fact[i-1]*i%M;
    
    cin>>n;
    for(int i=2; i<=n; i++){
        int p;
        cin>>p;
        nxt[p].push_back(i);
    }
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=n; i++) cin>>d[i];

    cout<<dfs(1)%M<<'\n';
    
    // for(int i=1; i<=n; i++) cout<<c[i]<<' ';
}
