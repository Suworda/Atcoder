#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;
int n;
int a[500005];
int sum[500005];

int _pow(int a, int b){
    if(b == 0) return 1;
    int m = _pow(a,b/2);
    if(b%2 == 0) return m*m%M;
    else return m*m%M*a%M;
}

int INV(int x){
    return _pow(x, M-2)%M;
}

int calc(int p, int q){
    return p * INV(q) % M;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << _pow(3,3) << '\n';
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
    
    int ans = 0;
    int cur = 0;
    for(int i=1; i<=(n+1)/2; i++){
        int l = i;
        int r = n-i+1;
        cur += (sum[r] - sum[l-1])%M;
        
        ans += calc(cur%M,i)%M;
        ans%=M;
    }

    cur = 0;
    for(int i=1; i<=n/2; i++){
        int l = i;
        int r = n-i+1;
        cur += (sum[r] - sum[l-1])%M;

        ans += calc(cur%M,n-i+1)%M;
        ans%=M;
    }

    cout << ans << '\n';


} 