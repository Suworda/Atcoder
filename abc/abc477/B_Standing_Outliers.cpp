#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,d;
int a[105];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>d;
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> ans;
    for(int i=1; i<=n; i++){
        bool yes = 1;
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            if(abs(a[i]-a[j]) < d) yes = 0;
        }
        if(yes) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ';
}