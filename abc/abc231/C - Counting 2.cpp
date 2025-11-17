#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[200001];

void sol(){
    int x;
    cin>>x;
    cout<<( a+n - lower_bound(a, a+n, x))<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);

    while(q--) sol();
}

