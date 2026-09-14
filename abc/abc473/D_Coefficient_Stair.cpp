#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
vector<int> v;
int ans = 0;

bool valid(int id, int r){
    for(int i=id; i<=n; i++){
        if(r%i == 0) return 1;
    }
    return 0;
}

void dfs(int id, int cur){
    if(cur > k) return;
    // cout << id << ' ' << x << ' ' << cur << '\n';
    if(id == n){
        if((k - cur) % id == 0){
            ans++;
            for(int y: v) cout << y << ' ';
            cout << (k - cur) / n << '\n';
        }
        return;
    }

    
    for(int i=0; i<=k; i++){
        if(cur+i*id > k) break;
        // if(!valid(id, k - cur)) continue;
        v.push_back(i);
        dfs(id+1, cur+i*id);
        v.pop_back();
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    if(n == 1){
        cout << k << '\n';
        return 0;
    }
    for(int i=0; i<=k; i++){
        v.push_back(i);
        dfs(2,i);
        v.pop_back();
    }

    // cout << ans << '\n';
    
} 