#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int a = 0, b = 0, c = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        x %= 1000;
        if(x == 0) continue;
        x = 1000 - x;
        string s = to_string(x);
        c += x / 100;
        x %= 100;
        b += x / 10;
        x %= 10;
        a += x;
    }

    cout << a << ' ' << b << ' ' << c << '\n';
    
} 