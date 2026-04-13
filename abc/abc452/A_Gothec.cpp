#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int m,d;
    cin>>m>>d;
    if(m == 1 && d == 7) cout<<"Yes\n";
    else if(m == 3 && d == 3) cout<<"Yes\n";
    else if(m == 5 && d == 5) cout<<"Yes\n";
    else if(m == 7 && d == 7) cout<<"Yes\n";
    else if(m == 9 && d == 9) cout<<"Yes\n";
    else cout<<"No\n";
}
