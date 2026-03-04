#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[128];
int mx=0;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>s;
    for(int i=0; i<s.size(); i++){
        cnt[s[i]]++;
        mx = max(mx,cnt[s[i]]);
    }

    for(int i=0; i<s.size(); i++){
        if(cnt[s[i]] != mx) cout<<s[i];
    }
    cout<<'\n';
    
}
