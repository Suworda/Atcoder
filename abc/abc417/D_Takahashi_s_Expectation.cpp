#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 10005;
int n,q;
int p[N], a[N], b[N];
int c[N];
bool vis[N][2005];
int dp[N][2005];

int f(int id, int x){
    if(vis[id][x]) return dp[id][x];
    if(id > n) return x;
    vis[id][x] = 1;
    
    int nxt_x = 0;

    if(p[id] >= x) nxt_x = x+a[id];
    else nxt_x = max(0LL, x-b[id]);

    return dp[id][x] = f(id+1, nxt_x);

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i]>>a[i]>>b[i];
        c[i] = c[i-1] + b[i];
    }

    cin>>q;
    while(q--){
        int x;
        cin>>x;
        auto it = lower_bound(c+1, c+n+1, x-1000);
        if(it == c+n+1){
            cout<<x-c[n]<<'\n';
            continue;
        }

        x -= *prev(it);
        int id = (it - c);
        cout << f(id, x) << '\n';

        

    }
    
}