#include <bits/stdc++.h>
using namespace std;

vector<int> a[9];
vector<int> b[9];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=0; i<m; i++){
        cin>>u>>v;
        b[u].push_back(v);
        b[v].push_back(u);
    }


}
