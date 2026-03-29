#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s;
int k;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>s>>k;
    int n = s.size();
    int cnt = 0;
    int ans = 0;
    for(int l=0, r=-1; l<n; l++){
        while(r+1 < n && cnt + (s[r+1] == '.') <= k){
            cnt += (s[r+1] == '.');
            r++;
        }
        ans = max(ans, r-l+1);
        cnt -= (s[l] == '.');
    }

    cout<<ans<<'\n';

}