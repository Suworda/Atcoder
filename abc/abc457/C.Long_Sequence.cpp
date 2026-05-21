#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
vector<int> a[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int l;
        cin>>l;
        for(int j=0; j<l; j++){
            int v;
            cin>>v;
            a[i].push_back(v);
        }
    }

    int len = 0;
    for(int i=0; i<n; i++){
        int c;
        cin>>c;
        int sz = a[i].size();
        // cout<<i<<' '<<len<<' '<<sz<<'\n';
        if(len + sz*c >= k){
            k-= len;
            cout<<a[i][(k-1 + sz)%sz]<<'\n';
            return 0;
        }
        len += sz*c;
    }
    
}
