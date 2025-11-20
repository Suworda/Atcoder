#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    string s[n];
    set<char> st[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
        for(int j=0; j<s[i].size(); j++) st[i].insert(s[i][j]);
    }

    int ans=0;
    int cur=0;
    for(int x=1; x < (1 << n); x++){
        //cout<<x<<'\n';
//        if(__builtin_popcount(x) != k) continue;

        cur=0;
        for(char i='a'; i<='z'; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if((x>>j) & 1) cnt+=st[j].count(i);
            }
            cur += (cnt==k);
        }
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';


}
