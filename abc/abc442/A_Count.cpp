#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    string s;
    cin>>s;
    int ans=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'i' || s[i] == 'j') ans++;
    }

    cout<<ans<<'\n';
    
}
