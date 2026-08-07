#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    bool ans = 1;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x >= 0) ans = 0;
    }

    cout << (ans ? "Yes\n" : "No\n");
    
}