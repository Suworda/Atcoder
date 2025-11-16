#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin>>n>>s;

    int t=count(s.begin(), s.end(), 'T');
    int a=n-t;

    if(t>a) cout<<'T'<<'\n';
    else if(a>t) cout<<'A'<<'\n';
    else{
        if(s[n-1]=='T') cout<<'A'<<'\n';
        else cout<<'T'<<'\n';
    }

}

