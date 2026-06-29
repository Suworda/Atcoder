#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
pair<int,int> p[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        p[i] = {x,y};
    }

    sort(p, p+n);

    int ans = 1;
    int last = p[0].second;
    for(int i=1; i<n; i++){
        if(p[i].second <= last){
            ans++;
            last = p[i].second;
        }
    }

    cout<<ans<<'\n';
    
}
