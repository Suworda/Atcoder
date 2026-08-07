#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int mx[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>m;
    memset(mx, -1, sizeof(mx));
    for(int i=0; i<n; i++){
        int c,s;
        cin>>c>>s;
        mx[c] = max(mx[c], s);
    }

    for(int i=1; i<=m; i++){
        cout<<mx[i]<<' ';
    }

}