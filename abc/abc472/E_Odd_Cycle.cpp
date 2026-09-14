#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
bitset<200005> vis;
int dep[200005];
vector<int> nxt[200005];
int parent[200005];
bool found = 0;

void init(){
    found = 0;
    for(int i=0; i<=n; i++){
        vis[i] = 0;
        dep[i] = 0;
        nxt[i].clear();
        parent[i] = 0;
    }
}

void print_ans(int st, int ed){
    // cout << "print_ans:";
    cout << dep[st] - dep[ed] + 1 << '\n';

    int x = st;
    while(x != ed){
        cout << x << ' ';
        x = parent[x];
    }
    cout << x << '\n';
}

void dfs(int u, int pa, int cur_dep){
    if(found || vis[u]) return;
    vis[u] = 1;
    dep[u] = cur_dep;
    // cout << u << "?\n";
    
    for(int v: nxt[u]){
        if(v == pa || found) continue;
        if(vis[v]){
            if(cur_dep - dep[v]%2 == 0){
                found = 1;
                print_ans(u,v);
            }
        }
        else{
            parent[v] = u;
            dfs(v,u,cur_dep+1);
        }
    }
}

void sol(){
    cin>>n>>m;
    init();
    while(m--){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    dfs(1,0,0);
    if(!found) cout << -1 << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

    
} 

/*
4
3 3
1 2
2 3
1 3

7 7
1 2
2 3
3 4
1 4
4 5
5 6
6 7

5 5
1 2
2 3
3 4
4 5
1 5

9 10
1 2
2 3
3 4
4 5
1 5
6 7
7 8
8 9
6 9
1 6
*/