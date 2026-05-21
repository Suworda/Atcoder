#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> a[200005];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        int l;
        cin>>l;
        int v;
        for(int j=1; j<=l; j++){
            cin>>v;
            a[i].push_back(v);
        }
    }

    int x,y;
    cin>>x>>y;
    cout<<a[x][y-1]<<'\n';
}
