#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
pair<int,int> x[200005];
pair<int,int> y[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>x[i].first;
    for(int i=0; i<n; i++) cin>>x[i].second;
    for(int i=0; i<m; i++) cin>>y[i].first;
    for(int i=0; i<m; i++) cin>>y[i].second;

    sort(x,x+n, greater<>());
    sort(y,y+m, greater<>());

    int p1=0, p2=0;
    multiset<int> d;
    while(p1 < n){
        while(x[p1].first <= y[p2].first){
            d.insert(y[p2].second);
            p2++;
        }

        auto it = d.lower_bound(x[p1].second);
        if(it != d.end()){
            d.erase(it);

        }else{
            cout<<"No\n";
            return 0;
        }

        p1++;
    }

    cout<<"Yes\n";
}