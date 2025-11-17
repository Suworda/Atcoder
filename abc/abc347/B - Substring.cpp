#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> st;

    string s;
    cin>>s;
    int n=s.size();

    for(int len=1; len<=n; len++){
        for(int l=0; l<=n-len; l++){
            st.insert(s.substr(l,len));
        }
    }

    cout<<st.size()<<'\n';
}
