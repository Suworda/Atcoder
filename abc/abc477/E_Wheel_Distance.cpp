#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

const int N = 200005;

int n,q;
int dis[N];
bitset<N> vis;
vector<pii> nxt[N];
int sum[N];
int tot = 0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=2; i<=n+1; i++){
        int w;
        cin>>w;
        tot += w;
        sum[i] = sum[i-1] + w;

        int a = i-1;
        int b = ((i-1) % n) + 1;
        nxt[a].push_back({b, w});
        nxt[b].push_back({a, w});
    }
    
    for(int i=1; i<=n; i++){
        int w;
        cin>>w;
        nxt[n+1].push_back({i,w});
        nxt[i].push_back({n+1,w});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;

    pq.push({0,n+1});

    while(pq.size()){
        auto [cur, u] = pq.top(); pq.pop();

        if(vis[u]) continue;
        dis[u] = cur;
        vis[u] = 1;

        for(auto [v, w]: nxt[u]){
            pq.push({cur+w, v});
        }
    }

    
    while(q--){
        ll ans1 = 0, ans2 = 0;
        int s,t;
        cin>>s>>t;
        ans1 = dis[s] + dis[t];

        int x = min(s, t);
        int y = max(s, t);

        if(y == n+1){
            cout << dis[x] << '\n';
            continue;
        }

        int z = sum[y] - sum[x];

        cerr << sum[y] << ' ' << sum[x] << '\n';
        cerr << dis[x] << ' ' << dis[y] << '\n';
        cerr << '\n';

        ans2 = min(z, tot - z);
        cout << min(ans1, ans2) << '\n';
    }

    
} 