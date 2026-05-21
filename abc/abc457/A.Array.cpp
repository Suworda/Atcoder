#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[105];
int x;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>x;

    cout<<a[x-1]<<'\n';
    
}
