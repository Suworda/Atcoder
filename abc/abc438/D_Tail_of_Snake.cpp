#include <bits/stdc++.h>
using namespace std;

#define ll long long


const int MAXN = 300005;
ll a[MAXN][3];
ll dp[MAXN][3];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=0; i<3; i++){
        for(int j=1; j<=n; j++){
            cin>>a[j][i];
        }
    }
    
    a[1][1] = 0;
    a[1][2] = 0;
    a[2][2] = 0;

    for(int i=1; i<=n; i++){
        for(int ty=0; ty<3; ty++){
            dp[i][ty] = max(dp[i-1][ty], dp[i-1][max(0, ty-1)]) + a[i][ty];
        }
    }

    cout<<dp[n][2]<<'\n';
}