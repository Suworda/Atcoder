#include <bits/stdc++.h>
using namespace std;

#define int long long

bitset<10000005> ok;
bitset<10000005> ok2;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ok2.set();
    int n;
    cin>>n;
    for(int x=1; x<=10000; x++){
        for(int y=x+1; y<=10000; y++){
            if(x*x + y*y > n) break;
            if(ok[x*x+y*y]) ok2[x*x+y*y] = false;
            ok[x*x+y*y] = true;
        }
    }

    vector<int> ans;

    for(int i=1; i<=n; i++){
        if(ok[i] && ok2[i]) ans.push_back(i);
    }

    cout<<ans.size()<<'\n';
    for(int x: ans){
        cout<<x<<' ';
    }
    // cout<<'\n';
    
}