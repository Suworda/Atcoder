#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[11],b[11];
set<char> st[11];
string s[200005];

string ans(int id){
    string t = s[id];
    if(t.size() != n) return "No\n";

    for(int i=0; i<t.size(); i++){
        if(!st[i].count(t[i])) return "No\n";
    }

    return "Yes\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
        b[i]--;
    }

    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>s[i];
        for(int j=0; j<n; j++){
            if(s[i].size() == a[j]) st[j].insert(s[i][b[j]]);
        }
    }

    for(int i=0; i<m; i++) cout<<ans(i);
    
}
