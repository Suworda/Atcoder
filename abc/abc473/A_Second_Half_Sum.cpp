#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n;
    int ans = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(i > n/2) ans += a[i];
    }

    cout << ans << '\n';
    
} 