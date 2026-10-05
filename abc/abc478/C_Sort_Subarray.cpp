#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    a[n+1] = 2e9;
    int s = 0, t = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(!s && a[i-1] > a[i]) s = i-1;
    }

    for(int i=n; i>=1; i--){
        cin>>a[i];
        if(!t && a[i] > a[i+1]) t = i+1;
    }

    multiset<int> mst;
    for(int i=1; i<=k; i++){
        mst.insert(a[i]);
    }

    int l = 1;
    int r = k;
    while(r <= n){
        if(l-1 <= s && t <= r+1 && a[l-1] <= *(mst.begin()) && *(prev(mst.end())) <= a[r+1]){
            cout << "Yes\n";
            return 0;
        }
        mst.erase(mst.find(a[l]));
        mst.insert(a[r+1]);
        l++; r++;
    }

    cout << "No\n";

} 