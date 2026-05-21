#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

char a[11][11];
int ans;

bool valid(int h, int w, int x, int y){
    for(int i=h; i<=x; i++){
        for(int j=w; j<=y; j++){
            if(a[i][j] != a[h+x-i][w+y-j]) return false;
        }
    }

    return true;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int h,w;
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            for(int x=i; x<=h; x++){
                for(int y=j; y<=w; y++){
                    ans += valid(i,j,x,y);
                }
            }
        }
    }

    cout<<ans<<'\n';
    
}
