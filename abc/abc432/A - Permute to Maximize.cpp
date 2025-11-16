#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if(b>a) swap(a,b);
    if(c>a) swap(a,c);
    if(c>b) swap(b,c);

    cout<<a<<b<<c<<'\n';
}

