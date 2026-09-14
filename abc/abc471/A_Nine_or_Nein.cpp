#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    double a,b;
    cin>>a>>b;
    if(a + b == 9 || a-b == 9 || a*b == 9 || a/b == 9) cout << "Nine\n";
    else cout << "Nein\n";
    
} 