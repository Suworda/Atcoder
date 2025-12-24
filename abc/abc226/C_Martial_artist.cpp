#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> from[200005];
int t[200005];
bitset<200005> vis;

ll dfs(int v){
    ll rst=0;

    for(int u: from[v]){
        if(!vis[u]){
            vis[u] = 1;
            rst += dfs(u);
        }
    }
    return rst + t[v];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>t[i];
        int k;
        cin>>k;
        while(k--){
            int a;
            cin>>a;
            from[i].push_back(a);
        }
    }

    cout << dfs(n);

}