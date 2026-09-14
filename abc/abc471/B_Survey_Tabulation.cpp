#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin>>n;
    map<string, int> cnt;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++) s[j] = toupper(s[j]);
        // cout << s <<'\n';
        cnt[s]++;
    }

    int ans = 0;
    for(auto x: cnt) ans = max(ans, x.second);

    cout << ans << '\n';
    
} 