#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long


signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = 'x' + s;
    s += 'x';

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += (s[i-1] == 'x' && s[i] == 'x' && s[i+1] == 'x');
    }

    cout << ans << '\n';
    
} 