#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

struct Graph{
    int n, max_id;
    set<pii> edged;
    vector<vector<pii>> nxt;
    vector<vector<int>> pre;
    vector<int> scc, outdeg;

    Graph(int _n): n(_n), pre(n+1), nxt(n+1), scc(n+1), outdeg(n+1) {}

    void add_edge(int t, int u, int v){
        nxt[u].push_back({t,v});
        pre[v].push_back(u);
        outdeg[u]++;
        edged.insert({u,v});
    }

    void find_scc(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> stk(n+1), dfn(n+1), low(n+1);
        int timer = 0;
        int id = 0;

        auto dfs = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            dfn[u] = low[u] = ++timer;
            vis[u] = instk[u] = 1;
            stk.push_back(u);

            for(auto [t,v]: nxt[u]){
                if(!vis[v]){
                    dfs(dfs, v);
                    low[u] = min(low[u], low[v]);
                }
                else if(instk[v]){
                    low[u] = min(low[u], dfn[v]);
                }
            }

            if(low[u] == dfn[u]){
                id++;
                max_id = id;

                int x;
                do{
                    x = stk.back();
                    stk.pop_back();
                    instk[x] = 0;
                    scc[x] = id;
                }while(x != u);
            }

        };

        for(int i=1; i<=n; i++) dfs(dfs, i);

    }

    bool have_solution(){
        for(int u=1; u<=n; u++){
            for(auto [t,v]: nxt[u]){
                if(scc[v] == scc[u] && t == 1) return false;
            }
        }
        return true;
    }

    
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;

    Graph g(n);

    while(q--){
        int t, u, v;
        cin>>t>>u>>v;
        g.add_edge(t,u,v);
    }
    
    g.find_scc();

    if(!g.have_solution()){
        cout << "No\n";
        return 0;
    }

    vector<vector<int>> vec(g.max_id+1);
    for(int i=1; i<=n; i++){
        vec[g.scc[i]].push_back(i);
    }
    
    vector<int> ans(n+1);
    int cur_id = g.max_id;
    for(int u=1; u<=g.max_id; u++){
        for(int x: vec[u]){
            ans[x] = cur_id;
        }
        cur_id--;
    }

    cout << "Yes\n";
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';

} 