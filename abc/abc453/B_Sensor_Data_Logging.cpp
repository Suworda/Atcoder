#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,x;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n>>x;
    vector<pair<int,int>> ans;
    for(int i=0; i<=n; i++){
        int a;
        cin>>a;
        if(!ans.size() || abs(a - ans.back().second) >= x) ans.push_back({i,a});
    }

    for(auto [a,b]: ans) cout<<a<<' '<<b<<'\n';
}
