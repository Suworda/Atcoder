#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005];
int cnt[200005];
int cnt2[200005];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    for(int i=1; i<=k; i++){
        cnt2[cnt[i]]++;
    }

    int ans = 0;
    int mx = 0;
    for(int i=n; i>=0; i--){
        if(cnt2[i]){
            mx = max(mx, i);
        }
    }

    if(mx-1 >= 1) cout << cnt2[mx] + cnt2[mx-1] << '\n';
    else cout << cnt2[mx] << '\n';


    
} 