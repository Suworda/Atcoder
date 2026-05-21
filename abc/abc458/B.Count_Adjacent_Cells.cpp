#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int h,w;

bool valid(int r, int c){
    return r>=1 && r<=h && c>=1 && c<=w;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            int rst = 0;
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                rst += valid(nr, nc);
            }
            cout<<rst<<' ';
        }
        cout<<'\n';
    }
    
}
