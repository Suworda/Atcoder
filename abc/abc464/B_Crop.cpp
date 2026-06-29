#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int h,w;
char a[55][55];
int u=2e9, d=0, l=2e9, r=0;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
            if(a[i][j] == '#'){
                u = min(u, i);
                d = max(d, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }

    for(int i=u; i<=d; i++){
        for(int j=l; j<=r; j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
}