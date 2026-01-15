#include <bits/stdc++.h>
using namespace std;

int m,n;
string s,t;
int ans = 2e9;

void try_(string x, string y){
    int rst = 0;
    for(int i=0; i<m; i++){
        rst += (x[i]+10 - y[i])%10;
    }

    ans = min(ans, rst);
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>m;
    cin>>s>>t;

    for(int i=0; i<n-m+1; i++){
        try_(s.substr(i,n), t);
    }

    cout<<ans<<'\n';


}