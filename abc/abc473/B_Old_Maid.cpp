#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[105];
bool x[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        x[a[i]] = !x[a[i]];
    }

    int ans = 0;
    for(int i=1; i<=100; i++){
        ans += x[i] * i;
    }

    cout << ans << '\n';

    
} 