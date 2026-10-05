#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,V;
int a[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n>>V;
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if(i + j + k <= V)ans = max(ans, a[i] + a[j] + a[k]);
            }
        }
    }
    cout << ans << '\n';
    
} 