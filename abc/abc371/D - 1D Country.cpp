#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<int,long long>> v(n+1);
    v[0]={-2e9,0};

    int x,p;
    for(int i=1; i<=n; i++) cin>>v[i].first;
    for(int i=1; i<=n; i++) cin>>v[i].second;
    sort(v.begin(), v.end());

    for(int i=2; i<=n; i++){
        v[i].second += v[i-1].second;
    }

    //for(auto &x: v) cout<<x.first<<':'<<x.second<<'\n';

    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;

        auto it_l = lower_bound(v.begin(), v.end() , make_pair(l,0LL));
        auto it_r = upper_bound(v.begin(), v.end() , make_pair(r,(long long)8e18));


        cout << (*prev(it_r)).second - (*prev(it_l)).second << '\n';

    }


}
