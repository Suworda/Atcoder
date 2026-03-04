#include <bits/stdc++.h>
using namespace std;

int n,m;
int v[1005];
int w[1005];
long long dp1[1005][50005], dp2[1005][50005];
long long ma=0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j-w[i] >= 0) dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-w[i]] + v[i]);
            else dp1[i][j] = dp1[i-1][j];
        }
    }

    for(int i=n; i>=1; i--){
        for(int j=0; j<=m; j++){
            if(j-w[i] >= 0) dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-w[i]] + v[i]);
            else dp2[i][j] = dp2[i+1][j];
        }
    }

    ma = dp1[n][m];

    for(int tg=1; tg<=n; tg++){
        //no
        bool is_A = true;
        for(int j=0; j<=m; j++){
            if(dp1[tg-1][j] + dp2[tg+1][m-j] == ma){
                is_A = false;
                break;
            }
        }
        if(is_A){
            cout<<'A';
            continue;
        }

        bool is_C = true;
        for(int j=0; j<=m-w[tg]; j++){
            if(dp1[tg-1][j] + dp2[tg+1][m-w[tg]-j] + v[tg] == ma){
                is_C = false;
                break;
            }
        }

        if(is_C) cout<<'C';
        else cout<<'B';
    }

    cout<<'\n';

    
}
