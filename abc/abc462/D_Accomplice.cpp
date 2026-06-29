#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,D;
int cnt[3000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>D;
    for(int i=0; i<n; i++){
        int s,t;
        cin>>s>>t;
        if(s + D <= t){
            cnt[s]++;
            cnt[t-D+1]--;
        }
    }

    for(int i=1; i<=3000000; i++) cnt[i] += cnt[i-1];

    ll ans = 0;
    for(int i=0; i<=3000000; i++){
        ans += cnt[i]*(cnt[i]-1)/2;
    }

    cout<<ans<<'\n';
    
}
