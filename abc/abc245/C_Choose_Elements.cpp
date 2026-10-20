#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005], b[200005];
bool dp[200005][2];

bool valid(int id, int x){
    if(dp[id][0] && abs(x - a[id]) <= k) return true;
    if(dp[id][1] && abs(x - b[id]) <= k) return true;
    return false;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=n; i++){
        dp[i][0] = valid(i-1, a[i]);
        dp[i][1] = valid(i-1, b[i]);
        if(!dp[i][0] && !dp[i][1]){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";    
} 