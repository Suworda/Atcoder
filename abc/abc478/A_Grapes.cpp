#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int ans[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n,m;
    cin>>n>>m;
    int id = 1;
    while(m){
        ans[id]++;
        m--;
        id++;
        if(id > n) id = 1;
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << '\n';
    }
    
} 