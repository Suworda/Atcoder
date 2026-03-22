#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int w[101][101];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    bool ans = false;
    cin>>n;
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            cin>>w[i][j];
            // cout<<i<<' '<<j<<'\n';
        }
    }

    for(int a=1; a<=n; a++){
        for(int b=a+1; b<=n; b++){
            for(int c=b+1; c<=n; c++){
                if(w[a][b] + w[b][c] < w[a][c]) ans = true;
                // cout<<w[a][b]<<' '<<w[b][c]<<' '<<w[a][c]<<'\n';
            }
        }
    }

    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
    
}
