#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k,t;
int a[200005];
vector<pair<int,int>> v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k>>t;
    int last = 0;
    int ans = 0;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++){
        if(a[i] >= t) break;
        if(last < a[i]) v.push_back({last, a[i]});
        last = a[i]+k;

    }
    if(last < t) v.push_back({last, t});

    for(auto [a,b]: v){
        ans += (b - a + k - 1) / k;
    }

    cout << ans << '\n';
} 
