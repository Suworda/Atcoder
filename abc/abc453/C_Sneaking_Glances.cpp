#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int l[25];
int ans;

void dfs(double p, int x, int cnt){
    if(x == n){
        ans = max(ans, cnt);
        return;
    }

    dfs(p + l[x], x+1, cnt + ((p > 0 && p+l[x] < 0) || (p < 0 && p+l[x] > 0)) );
    dfs(p - l[x], x+1, cnt + ((p > 0 && p-l[x] < 0) || (p < 0 && p-l[x] > 0)) );
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>l[i];
    }

    dfs(0.5, 0, 0);

    cout<<ans<<'\n';

}
