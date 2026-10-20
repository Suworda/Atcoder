#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,L,R;
int a[200005];
int psum[200005];
int ssum[200005];
int dp_l[200005][2];
int dp_r[200005][2];
int mi_dp_r = 2e18, mi_dp_l = 2e18;

void upd(int &ans, int l, int r){
    int x = min(dp_l[l][0], dp_l[l][1]);
    int y = min(dp_r[r][0], dp_r[r][1]);
    ans = min(ans, x + y);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>L>>R;
    for(int i=1; i<=n; i++) cin>>a[i];

    dp_l[0][0] = 0;
    dp_l[0][1] = 0;
    dp_r[n+1][0] = 0;
    dp_r[n+1][1] = 0;

    for(int i=1; i<=n; i++) psum[i] = psum[i-1] + a[i];
    for(int i=n; i>=1; i--) ssum[i] = ssum[i+1] + a[i];

    dp_l[1][0] = a[1];
    dp_l[1][1] = L;
    for(int i=2; i<=n; i++){
        dp_l[i][0] = min(dp_l[i-1][0], dp_l[i-1][1]) + a[i];
        dp_l[i][1] = L*i;
    }

    dp_r[n][0] = a[n];
    dp_r[n][1] = R;
    for(int i=n-1; i>=1; i--){
        dp_r[i][0] = min(dp_r[i+1][0], dp_r[i+1][1]) + a[i];
        dp_r[i][1] = R*(n-i+1);
    }
    

    int ans = 2e18;
    for(int i=1; i<=n; i++){
        upd(ans, i-1, i);
        upd(ans, i, i+1);
    }

    cout << ans << '\n';

    
} 