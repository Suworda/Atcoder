#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
ll a[15];
int ty[15];
ll b[15];
vector<int> v;

void dfs(int id, int x){
    if(id > n){
        ll rst = 0;
        for(int i=1; i<=x; i++){
            rst ^= b[i];
        }
        v.push_back(rst);
        return;
    }

    for(int i=1; i<=x; i++){
        b[i] += a[id];
        dfs(id+1,x);
        b[i] -= a[id];
    }

    b[x+1] += a[id];
    dfs(id+1, x+1);
    b[x+1] -= a[id];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    dfs(1,0);
    sort(v.begin(), v.end());
    cout<<(unique(v.begin(), v.end()) - v.begin())<<'\n';
}