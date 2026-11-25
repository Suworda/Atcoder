#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n, k;
int a[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    int r = 0;
    int ans = 0;
    int cur = 0;
    for(int l=1; l<=n; l++){
        while(r+1 <= n && cur < k){
            cur += a[r+1];
            r++;
        }

        if(cur >= k) ans += n-r+1;

        cur -= a[l];
    }

    cout << ans << '\n';
    
} 