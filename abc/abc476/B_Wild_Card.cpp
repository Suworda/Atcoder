#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=0; i<n; i++){
        if(t[i] != '*' && s[i] != t[i]){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    
} 