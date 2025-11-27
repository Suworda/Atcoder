#include <bits/stdc++.h>
using namespace std;

unordered_set<int> apr;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n,x;
    cin>>n>>x;

    int a[n];
    long long ans=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        apr.insert(a[i]);
    }

    for(int i=0; i<n; i++){
        if(apr.count(x+a[i])){
            cout<<"Yes\n";
            return 0;
        }
    }

    cout<<"No\n";
}
