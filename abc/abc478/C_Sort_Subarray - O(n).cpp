#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n, k;
int a[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    //L:
    int L = 2e9;
    int mi = 2e9;
    for(int i=n; i>=1; i--){
        mi = min(mi, a[i]);
        if(a[i] > mi){
            L = i;
        }
    }

    a[n+1] = 2e9;
    int R = 0;
    int mx = 0;
    for(int i=1; i<=n; i++){
        mx = max(mx, a[i]);
        if(a[i] < mx){
            R = i;
        }
    }

    cout << (R - L + 1 <= k ? "Yes" : "No") << '\n';
    
} 