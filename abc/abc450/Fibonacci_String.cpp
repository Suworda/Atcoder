#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string x,y;
ll sum[20005][30];
ll dp[105][30];
ll sz[105];
int id = 2;

ll f(int k, int c){
    ll rst = 0;
    for(int i=id; i>=2; i--){
        if(sz[i] <= k){
            rst += dp[i][c];
            k -= sz[i];
        }
    }

    if(k){
        rst += sum[k][c];
    }
    return rst;
}

ll get_ans(int l, int r, int c){
    return f(r, c) - f(l-1, c);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>x>>y;

    for(int i=0; i<x.size(); i++){
        dp[0][x[i] - 'a']++;
    }
    sz[0] = x.size();
    for(int i=0; i<y.size(); i++){
        dp[1][y[i] - 'a']++;
    }
    sz[1] = y.size();

    string yx = y + x;
    for(int i=1; i<=yx.size(); i++){
        for(int j=0; j<26; j++){
            sum[i][j] = sum[i-1][j];
        }
        sum[i][yx[i-1] - 'a']++;
    }

    while(true){
        for(int i=0; i<26; i++){
            dp[id][i] = dp[id-1][i] + dp[id-2][i];
            sz[id] = sz[id-1] + sz[id-2];
        }
        // cout<<dp[id][1]<<'\n';
        if(sz[id] > 1e18) break;
        id++;
    }

    int q;
    cin>>q;
    while(q--){
        ll l,r;
        char c;
        cin>>l>>r>>c;
        cout<<get_ans(l,r,c-'a')<<'\n';
    }
    
}
