#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void sol(){
    int n, a, b;
    cin>>n>>a>>b;
    if(n%2 != 0 || (a+b)%2 == 0){
        cout<<"No\n";
        return;
    } 
    // if(n == 2){
    //     cout<<"Yes\nDR\n";
    //     return;
    // }

    cout<<"Yes\n";
    for(int i=1; i<=(a-1)/2; i++){
        for(int j=0; j<n-1; j++) cout<<"R";
        cout<<"D";
        for(int j=0; j<n-1; j++) cout<<"L";
        cout<<"D";
    }

    for(int i=1; i<=(b-1)/2; i++){
        cout<<"DRUR";
    }

    if(b%2 == 1) cout<<"RD";
    else cout<<"DR";

    for(int i=1; i<=(n-b)/2; i++){ //////
        cout<<"RURD";
    }

    for(int i=1; i<=(n-a)/2; i++){
        cout<<"D";
        for(int j=0; j<n-1; j++) cout<<"L";
        cout<<"D";
        for(int j=0; j<n-1; j++) cout<<"R";
    }

    cout<<'\n';
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
    
}
