#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

struct X{
    int v;
    bool operator< (const X &b) const{
        return v > b.v;
    }
};

X a[500005];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].v;
    }
    
    multiset<X> mst;
    for(int i=1; i<=2; i++){
        mst.insert(a[i]);
    }

    for(int i=3; i<=n; i++){
        mst.insert(a[i]);
        auto it = mst.begin();
        it++;it++;
        cout << (*it).v << '\n';
    }
} 