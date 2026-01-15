#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n,k;
    cin>>n>>k;
    set<pair<int,int>> st;
    vector<int> v;
    vector<int> ans(n+1, -1);

    int p;
    for(int i=1; i<=n; i++){
        cin>>p;
        auto it = st.lower_bound(p);
        if(it == st.end()){
            v.push_back(p);
        }

        if(st.size()>=k){
            for(int x: st){
                ans[x]=i;
            }
            apr.clear();
        }
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<'\n';



}
