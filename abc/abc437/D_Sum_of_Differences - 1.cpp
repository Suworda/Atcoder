#include <bits/stdc++.h>
using namespace std;

#define ll long long

int M = 998244353;

ll a[300005];
ll b[300005];
ll rst[300005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);

    for(int i=1; i<=m; i++){
        cin>>b[i];
    }
    sort(b+1, b+m+1);

    for(int i=1; i<=n; i++){
        rst[0] += abs(a[i]);
    }

    for(int i=1; i<=n; i++){
        rst[1] += abs(a[i]-a[1]);
        
    }
    // rst[0]%=M;
    // rst[1]%=M;
    //cout<<rst[1]<<'\n';
    for(int i=2; i<=n; i++){
        rst[i] = rst[i-1] + (2*(i-1)-n)*(a[i]-a[i-1]);
        rst[i] = (rst[i]%M+M)%M;
        //cout<<rst[i]<<'\n';
    }

    ll ans=0;
    for(int i=1; i<=m; i++){
        auto it = upper_bound(a+1, a+n+1, b[i]);
        it--;
        //cout<<*it<<' ';
        int id = it - a;
        ll p = *it;
        ans += rst[id] + (b[i] - p)*((it-a) - (a+n-it));
        //cout<< (it - a) <<' '<<(a+n+1-it)<<'\n';;
        //cout<<ans<<'\n';
        ans = (ans%M+M)%M;
    }

    cout<<ans<<'\n';



}