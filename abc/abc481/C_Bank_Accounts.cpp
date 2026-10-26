#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int q;
    cin>>q;
    map<string, int> id;
    int cur = 1;
    while(q--){
        string s;
        cin>>s;
        if(id.find(s) == id.end()){
            id[s] = cur++;
        }
        cout << id[s] << '\n';
    }
    
} 