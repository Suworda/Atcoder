#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[105], b[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    bool ans = 1;
    for(int i=1; i<=n; i++){
        if(a[b[i]] != i) ans = false;
    }

    cout<<(ans ? "Yes\n" : "No\n");
    
}
