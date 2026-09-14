#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    string s;
    cin>>s;
    for(int i=0; i<s.size()-1; i++){
        cout << s[i] << 'o';
    }
    cout << s[s.size()-1] << '\n';
    
} 