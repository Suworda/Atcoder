#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
pair<int,int> bridge[100005];
int parent[100005];
long long sz[100005];
long long cur;
vector<long long> ans;

int fpa(int x){
    if(parent[x] == x) return x;
    return parent[x] = fpa(parent[x]);
}

void update(int a, int b){
    int pa = fpa(a);
    int pb = fpa(b);
    if(pa != pb){
        cur -= sz[pa]*sz[pb];
        sz[pa] += sz[pb];
        sz[pb] = 1;
        parent[pb] = pa;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    iota(parent+1, parent+1+n, 1);
    fill(sz+1, sz+1+n, 1);
    cur = n*(n-1)/2;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        bridge[i] = {a,b};
    }

    for(int i=m-1; i>=0; i--){
        ans.push_back(cur);
        auto [a,b] = bridge[i];
        update(a,b);
    }

    reverse(ans.begin(), ans.end());
    for(auto &x: ans) cout<<x<<'\n';


    
}
