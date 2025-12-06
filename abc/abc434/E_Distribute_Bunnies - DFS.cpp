#include <bits/stdc++.h>
using namespace std;

set<int> vis;
map<int,vector<int>> edge;
bool is_tree = true;
int cnt_v;
int ans;

int dfs(int v, int from){
    int cnt=0;
    vis.insert(v);
    for(int next: edge[v]){
        if(from == next) continue;

        if(!vis.count(next)) cnt += dfs(next,v);
        else is_tree = false;
    }

    return cnt + 1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int x,r;
    for(int i=0; i<n; i++){
        cin>>x>>r;
        int a = x+r;
        int b = x-r;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // dfs:
    for(auto v: edge){
        if(!vis.count(v.first)){
            is_tree = true;
            cnt_v = dfs(v.first, v.first);
            //cout<<cnt_v<<' '<<is_tree<<'\n';
            if(is_tree) ans += cnt_v-1;
            else ans += cnt_v;
        }
    }

    cout<<ans<<'\n';
}