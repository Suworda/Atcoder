#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> v[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        int j;
        cin>>j;
        while(j--){
            int x;
            cin>>x;
            v[x].push_back(i);
        } 
    }

    for(int i=1; i<=n; i++){
        cout<<v[i].size();
        for(int x: v[i]) cout<<' '<<x;
        cout<<'\n';
    }
    
}
