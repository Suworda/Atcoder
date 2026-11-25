#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

using piii = tuple<int,int,int>;
vector<piii> nxt[200005];
bitset<200005> vis;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        nxt[a].push_back({b, c, i});
        nxt[b].push_back({a, c, i});
    }

    priority_queue<piii, vector<piii>, greater<>> pq;

    pq.push({0, 1, 0});

    vector<int> ans;
    while(pq.size()){
        auto [cur, u, id] = pq.top(); pq.pop();
        if(vis[u]) continue;

        vis[u] = 1;
        if(id) ans.push_back(id);

        for(auto [v, w, id]: nxt[u]){
            pq.push({cur + w, v, id});
        }
        
    }

    for(int x: ans) cout << x << ' ' ;
    cout << '\n';

} 