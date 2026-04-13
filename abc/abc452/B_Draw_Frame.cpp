#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int h,w;
    cin>>h>>w;
    char a[h+5][w+5];
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            a[i][j] = '#';
        }
    }

    for(int i=2; i<=h-1; i++){
        for(int j=2; j<=w-1; j++){
            a[i][j] = '.';
        }
    }
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
}
