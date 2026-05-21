#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s;
ll ans;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'C') ans += min(i, (int)s.size()-i-1)+1;
    }

    cout<<ans<<'\n';
    
    
}
