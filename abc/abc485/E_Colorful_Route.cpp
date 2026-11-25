#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n, m;
vector<pair<int,int>> nxt[200005];
int vis[200005];
int color[200005][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        nxt[a].push_back({b, c});
    }

    queue<tuple<int,int,int>> q;
    q.push({1, 0, 0});
    vis[1]++;

    while(q.size()){
        auto [u, last, dis] = q.front(); q.pop();

        if(u == n){
            cout << dis << '\n';
            return 0;
        }

        for(auto [v, c]: nxt[u]){
            if(c == last || vis[v] == 2) continue;

            if(c == color[v][0] || c == color[v][1]) continue;

            q.push({v, c, dis+1});
            color[v][vis[v]++] = c;
        }
    }

    cout << -1 << '\n';
}
