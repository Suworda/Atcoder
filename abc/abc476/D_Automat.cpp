#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,k;
int x,y;
int a[200005], b[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k;
    cin>>x>>y;
    int tot = y*k + x;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    int id2 = 0;
    for(int i=1; i<=m; i++){
        if(y - ((b[i]/k) + (b[i]%k != 0)) >= 0){
            tot -= b[i];
            y -= (b[i]/k) + (b[i]%k != 0);
            x += b[i]%k;
            id2 = i;
        }
    }

    int ans = id2;
    cerr << tot << '\n';
    
    for(int i=1; i<=n; i++){
        tot -= a[i];
        while(tot < 0 && id2 >= 1){
            tot += b[id2];
            id2--;
        }

        if(tot >= 0) ans = max(ans, id2 + i);
        // cerr << id2 << ' ' << tot << '\n';
    }

    cout << ans << '\n';

    
    
} 