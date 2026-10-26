#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

struct Graph{
    int n, m;
    vector<vector<pii>> nxt;
    vector<int> dis;

    Graph(int _n, int _m): n(_n), m(_m), nxt(n+1), dis(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back({b,1});
    }

    void set_edges(){
        for(int i=1; i<=n; i++){
            sort(nxt[i].begin(), nxt[i].end());
            if(nxt[i].size()) nxt[i][0] = {nxt[i][0].first, 0};
        }
    }

    void init_dis(){
        for(int i=1; i<=n; i++) dis[i] = 2e9;
    }

    int get_ans(int s, int t){
        vector<bool> vis(n+1);
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, s});

        while(pq.size()){
            auto [cur, u] = pq.top(); pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            dis[u] = cur;
            for(auto [v,w]: nxt[u]){
                pq.push({cur+w, v});
            }
        }

        return (dis[t] == 2e9 ? -1 : dis[t]);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,s,t;
    cin>>n>>m>>s>>t;

    Graph g(n,m);

    while(m--){
        int a, b;
        cin>>a>>b;
        g.add_edge(a, b);
    }

    g.set_edges();

    g.init_dis();

    int ans = g.get_ans(s, t);

    cout << ans << '\n';
    
} 