#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
set<pair<int,int>> st;
set<int> nxt[200005];
int deg[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int cnt = 0;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(st.count({a,b})) continue;
        st.insert({a,b});
        st.insert({b,a});
        deg[a]++;
        deg[b]++;
        nxt[a].insert(b);
        nxt[b].insert(a);
        cnt++;
    }

    int mx = 0;
    for(int i=1; i<=n; i++){
        if(deg[i] > mx){
            mx = deg[i];
        }
    }

    vector<int> vec;
    for(int i=1; i<=n; i++){
        if(deg[i] == 1){
            vec.push_back(i);
        }
    }

    int ans = 0;

    for(int u: vec){
        vector<pair<int,int>> rmd;
        for(int v: nxt[u]){
            rmd.push_back({u,v});
            rmd.push_back({v,u});
            st.erase({u,v});
            st.erase({v,u});
            deg[u]--;
            deg[v]--;
            cnt--;
        };
        if(cnt - deg[u] == 0){
            int x = 0;
            for(int i=1; i<=n; i++) x += (cnt - deg[i] == 0);
    
            if(x == 1) cout << 1 << '\n';
            else cout << 2 << '\n';
    
        }

        for(auto [u,v]: rmd){
            st.insert({u,v});
            st.insert({v,u});
        }
    }





    // for(int i=1; i<=n; i++){
    //     if(deg[i] == 1){
    //         deg[i]--;
    //         int v = nxt[i][0];
    //         deg[v]--;
    //     }
    // }

    // vector<int> v;
    // int cnt = 0;
    // for(int i=1; i<=n; i++){
    //     if(deg[i] > 0){
    //         v.push_back(i);
    //         cnt++;
    //     }
    // }
    



    // if(cnt > 3) cout << 0 << '\n';
    // else{
    //     for(int x: v) cout << x << ' ';
    //     cout << '\n';
    // }
} 