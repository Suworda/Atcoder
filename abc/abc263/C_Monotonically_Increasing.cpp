#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> v;

void dfs(int id, int x){
    if(id > n){
        for(int num: v) cout<<num<<' ';
        cout<<'\n';
        return;
    }

    for(int i=x+1; i<=m; i++){
        v.push_back(i);
        dfs(id+1, i);
        v.pop_back();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    dfs(1,0);
    
}
