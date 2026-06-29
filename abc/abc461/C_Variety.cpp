#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k,m;
multiset<int> gems;
int mx[200005];
multiset<int> mst;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k>>m;
    for(int i=0; i<n; i++){
        int c,v;
        cin>>c>>v;
        gems.insert(v);
        mx[c] = max(mx[c], v);
    }

    sort(mx+1, mx+n+1, greater<>());

    int ans = 0;
    for(int i=1; i<=m; i++){
        ans += mx[i];
        gems.erase(gems.find(mx[i]));
    }

    vector<int> v;
    for(auto x: gems){
        v.push_back(x);
    }

    reverse(v.begin(), v.end());

    for(int i=0; i<k-m; i++){
        ans += v[i];
    }

    cout<<ans<<'\n';



}
