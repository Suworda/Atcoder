#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
const ll INF = 4e18;

struct Graph{
    int n;
    vector<vector<int>> nxt0, nxt1;

    Graph(int _n): n(_n), nxt0(n+1), nxt1(n+1) {}

    void add_edge(int a, int b){
        nxt0[a].push_back(b);
        nxt1[b].push_back(a);
    }

    int get_dis(int s, int t, int x){
        vector<array<int,2>> dis(n+1, {INF, INF});
        vector<array<bool, 2>> vis(n+1, {0, 0});

        priority_queue<tiii, vector<tiii>, greater<>> pq;
        pq.push({0, s, 0});

        while(pq.size()){
            auto [cur, u, rev] = pq.top(); pq.pop();

            if(vis[u][rev]) continue;

            dis[u][rev] = cur;
            vis[u][rev] = 1;
            
            if(!rev){
                for(int v: nxt0[u]){
                    pq.push({cur+1, v, rev});
                }
                for(int v: nxt1[u]){
                    pq.push({cur+x+1, v, rev^1});
                }
            }
            else{
                for(int v: nxt1[u]){
                    pq.push({cur+1, v, rev});
                }
                for(int v: nxt0[u]){
                    pq.push({cur+x+1, v, rev^1});
                }
            }
        }

        return min(dis[t][0], dis[t][1]);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;
    Graph g(n);

    while(m--){
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    int ans = g.get_dis(1, n, x);

    cout << ans << '\n';
    
}