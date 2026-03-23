#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct OB{
    int s,t,x;
    bool operator< (const OB &b) const{
        return x < b.x;
    }
}ob[200005];

int n,q;
int ans[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=0; i<n; i++){
        int s,t,x;
        cin>>s>>t>>x;
        ob[i] = {s,t,x};
    }
    sort(ob, ob+n);

    set<pair<int,int>> d;
    for(int i=0; i<q; i++){
        int di;
        cin>>di;
        d.insert({di,i});
    }

    for(int i=0; i<n; i++){
        auto it = d.lower_bound({ob[i].s - ob[i].x, 0});
        while(it != d.end() && it->first < ob[i].t - ob[i].x){
            ans[it->second] = ob[i].x;
            it = d.erase(it);
        }
    }

    for(int i = 0; i < q; i++) cout << (ans[i] ? ans[i] : -1) << '\n';

}