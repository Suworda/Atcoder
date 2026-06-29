#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int a[200005];
int b[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    sort(a,a+n);
    sort(b,b+m);

    int x=0, y=0;

    int ans = 0;
    while(x < n && y < m){
        if(a[x]*2 < b[y]){
            x++;
            
        }else if(a[x]*2 >= b[y]){
            ans++;
            x++;
            y++;
        }
    }

    cout<<ans<<'\n';
}
