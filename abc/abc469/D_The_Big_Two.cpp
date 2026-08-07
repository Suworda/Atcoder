#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
set<pair<int,int>> st;
set<int> nxt[200005];
int deg[200005];
vector<int> v[200005];

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

    for(int i=1; i<=n; i++){
        v[deg[i]].push_back(i);
    }

    int ans = 0;
    for(int i=0; i<=n; i++){
        for(int a: v[i]){
            for(int b: v[cnt-i]){
                if(a != b && !st.count({a,b})){
                    // cout << a << ' ' << b << '\n';
                    ans++;
                }
            }
            for(int b: v[cnt-i+1]){
                if(a != b && st.count({a,b})) ans++;
            }
        }
    }

    cout << ans/2 << '\n';
} 