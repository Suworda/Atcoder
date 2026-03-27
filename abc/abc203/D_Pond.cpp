#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k,tg;
int a[805][805];
int x[805][805];
int sum[805][805];

int cnt(int r, int c){
    if(r-k < 0 || c-k < 0) return -1;
    return sum[r][c] - sum[r-k][c] - sum[r][c-k] + sum[r-k][c-k];
}

bool valid(int v){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            x[i][j] = (a[i][j] <= v);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x[i][j];
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cnt(i,j) >= tg) return true;
        }
    }

    return false;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    tg = k*k - (k*k/2 + 1) + 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    int l=0, r=2e9, ans=-1;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    cout<<ans<<'\n';

}