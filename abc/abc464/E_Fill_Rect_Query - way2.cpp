#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int h,w,q;
vector<vector<int>> v;
string x;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w>>q;
    x.resize(q+2);
    v.resize(h+2, vector<int>(w+2));
    for(int i=1; i<=q; i++){
        int r,c;
        cin>>r>>c>>x[i];
        v[r][c] = i;
    }
    
    
    for(int i=h; i>0; i--){
        for(int j=w; j>0; j--){
            // cout<<i<<' '<<j<<'\n';
            v[i][j] = max({v[i][j], v[i+1][j], v[i][j+1]});
        }
    }
    
    x[0] = 'A';
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout<<x[v[i][j]];
        }
        cout<<'\n';
    }



}