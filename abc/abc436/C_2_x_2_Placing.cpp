#include <bits/stdc++.h>
using namespace std;

int n,m;
set<pair<int,int>> blocked;

bool place(int r, int c){
    for(int i=r; i<=r+1; i++){
        for(int j=c; j<=c+1; j++){
            if(blocked.count({i,j})) return false;
        }
    }

    for(int i=r; i<=r+1; i++){
        for(int j=c; j<=c+1; j++){
            blocked.insert({i,j});
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int r,c;
    int ans = 0;
    for(int i=0; i<m; i++){
        cin>>r>>c;
        ans += place(r,c);
    }

    // for(auto x: blocked){
    //     cout<<x.first<<' '<<x.second<<'\n';

    // }

    cout<<ans<<'\n';
}