#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 300005;
int n,m;
// int a[N], d[N], b[N];
vector<tuple<int,int,int>> v;
multiset<int> mst;
set<int> st;
int ans[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int a,d,b;
        cin>>a>>d>>b;
        st.insert(a);
        mst.insert(a);
        v.push_back({d,a,b});
    }

    sort(v.begin(), v.end());

    int id = 0;
    for(int i=1; i<=m; i++){
        bool flag = 0;
        // cerr<<i<<'\n';
        if(id < v.size()){
            auto [d,a,b] = v[id];
            // cerr<<d<<' '<<a<<' '<<b<<'\n';
            if(d == i){
                mst.erase(mst.find(a));
                if(mst.find(a) == mst.end()) st.erase(a);
                mst.insert(b);
                st.insert(b);
                id++;
                flag = 1;
                // i--;
                // if(id >= v.size()){
                //     cout<<st.size()<<'\n';
                //     continue;
                // }
                // auto [d2, a2, b2] = v[id];

                // d = d2;
                // a = a2;
                // b = b2;
            }
        }

        ans[i] = st.size();
        if(flag) i--;

        // cout<<st.size()<<'\n';
    }

    for(int i=1; i<=m; i++) cout<<ans[i]<<'\n';
    
}