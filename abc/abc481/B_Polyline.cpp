#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n,k;
    cin>>n>>k;
    int ans = 0;
    int last = -1;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x == k){
            ans++;
            last = x;
            continue;
        }

        if(last != -1){
            if(last > k && k > x) ans++;
            else if(last < k && k < x) ans++;
        }
        last = x;
    }
    cout << ans << '\n';
    
} 