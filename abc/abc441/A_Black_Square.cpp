#include <bits/stdc++.h>
using namespace std;

bool black[10101][10101];

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int x,y;
    cin>>x>>y;
    for(int i=x; i<x+100; i++){
        for(int j=y; j<y+100; j++){
            black[i][j]=1;
        }
    }

    cin>>x>>y;
    if(black[x][y]) cout<<"Yes\n";
    else cout<<"No\n";
    
}
