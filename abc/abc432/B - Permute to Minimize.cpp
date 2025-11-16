#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    sort(s.begin(),s.end());

    if(s[0]=='0'){
        for(int i=0; i<s.size(); i++){
            if(s[i]!='0'){
                swap(s[0],s[i]);
                break;
            }
        }
    }

    cout<<s<<'\n';
}

