#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    cin>>s;
    bool start = 0;
    for(int i=0; i<n; i++){
        if(s[i] != 'o') start = 1;
        if(start) cout<<s[i];
    }
    
}
