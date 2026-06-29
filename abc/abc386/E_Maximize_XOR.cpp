#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
ll a[200005];
int ans = 0;
ll tot;

void dfs(int id, ll cur, int cnt){
    if(cnt == k){
        ans = max(ans , cur^tot);
        return;
    }
    for(int i=id; n-i+1 >= k-cnt; i++){
        dfs(i+1, cur^a[i], cnt+1);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        tot ^= a[i];
    }

    if(k * 2 > n){
        k = n-k;
    }else{
        tot = 0;
    }
    dfs(1,0,0);
    cout<<ans<<'\n';
}
