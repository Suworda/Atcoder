#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
set<string> st;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        string x;
        for(int j=0; j<s.size(); j++){
            x += (s[j] == '1' ? '0' : '1');
        }
        st.insert(x);
    }   

    for(int i=0; i<(1<<min(m,15LL)); i++){
        string x;
        for(int i=0; i<m-15; i++) x += '0';

        for(int j=min(m,15LL)-1; j>=0; j--){
            // cerr<<j<<' ';
            x += '0' + ((i >> j) & 1);
        }

        if(!st.count(x)){
            cout<<"Yes\n";
            cout<<x<<'\n';
            return 0;
        }
        // cout<<x<<' ';
    }

    cout<<"No\n";
    
}