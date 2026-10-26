#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll INF = 2e18;
int n,m;
int a[1005];
int b[1005];
int c[1005];
int dp[1005][10005];

void init_dp(){
    for(int i=0; i<=m; i++){
        for(int j=1; j<(1<<n); j++){
            dp[i][j] = INF;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a[i]>>b[i];
        for(int j=0; j<b[i]; j++){
            int x;
            cin>>x;
            c[i] += (1 << (x-1));
        }
    }

    init_dp();

    for(int i=0; i<=m-1; i++){
        for(int j=0; j<(1 << n); j++){
            int nxt = i+1;
            int now = i;
            dp[nxt][j] = min(dp[nxt][j], dp[now][j]);
            dp[nxt][j | c[nxt]] = min(dp[nxt][j | c[nxt]], dp[now][j] + a[nxt]);
        }
    }

    cout << (dp[m][(1<<n)-1] < INF/2 ? dp[m][(1<<n)-1] : -1) << '\n';

} 