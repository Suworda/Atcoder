#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

struct Graph{
    int n;
    vector<vector<pii>> nxt;

    Graph(int _n): n(_n), nxt(n+1) {}

    void add_edge(int a, int b, int c){
        nxt[a].push_back({b, c});
    }

    void print_ans(){
        vector<bool> vis(n+1);
        priority_queue<pii, vector<pii>, greater<>> pq;
        vector<int> dis(n+1);
        pq.push({0, 1});

        while(pq.size()){
            auto [cur, u] = pq.top(); pq.pop();
            if(vis[u]) continue;

            vis[u] = 1;
            dis[u] = cur;

            for(auto [v, w]: nxt[u]){
                pq.push({cur+w, v});
            }
        }

        cout << dis[n] << '\n';
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    Graph g(n);
    
    for(int i=1; i<=n-1; i++){
        int a, b, x;
        cin >> a >> b >> x;
        g.add_edge(i, i+1, a);
        g.add_edge(i, x, b);
    }

    g.print_ans();

}