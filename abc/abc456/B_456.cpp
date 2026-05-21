#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int a[7][7];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=6; j++){
            int x;
            cin>>x;
            a[i][x]++;
        }
    }

    double ways = 0;
    ways += a[1][4] * a[2][5] * a[3][6];
    ways += a[1][4] * a[2][6] * a[3][5];
    ways += a[1][5] * a[2][4] * a[3][6];
    ways += a[1][5] * a[2][6] * a[3][4];
    ways += a[1][6] * a[2][5] * a[3][4];
    ways += a[1][6] * a[2][4] * a[3][5];
    
    cout<<fixed<<setprecision(15)<<ways/216<<'\n';
    
}
