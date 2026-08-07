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
        if(id < v.size()){
            auto [d,a,b] = v[id];
            if(d == i){
                mst.erase(mst.find(a));
                if(mst.find(a) == mst.end()) st.erase(a);
                mst.insert(b);
                st.insert(b);
                id++;
                flag = 1;
            }
        }

        ans[i] = st.size();
        if(flag) i--;
    }

    for(int i=1; i<=m; i++) cout<<ans[i]<<'\n';
    
}

int &a = pair.first;
int &b = pair.second;

auto [a,b] = pair;

1 2 3 5 6 6 
1 2 3 5 4 6 erase(6) insert(4)