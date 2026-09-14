#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;
int n,k;
int a[200005];
int fact[200005];
int sum[200005];

int _pow(int a, int b){
    if(b == 0) return 1;
    int m = _pow(a,b/2);
    if(b%2 == 0) return m*m%M;
    else return m*m%M*a%M;
}

int INV(int x){
    return _pow(x,M-2);
}

int C(int a, int b){
    if(a < 0 || b < 0 || b > a) return 0;
    return fact[a] * INV(fact[a-b])%M * INV(fact[b])%M;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin>>n>>k;
    fact[0] = 1;
    for(int i=1; i<=200000; i++) fact[i] = fact[i-1] * i%M;
    
    for(int i=1; i<=n; i++) cin>>a[i];
    if(n == 1){
        cout << a[1]*a[1]%M << '\n';
        return 0;
    }
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
    
    ll ans = 0;
    // for(int i=1; i<=n; i++){
    //     ans += (C(n-1,k-1) * (a[i] * a[i])) + (2*a[i]*C(n-2,k-2) * (sum[n]-sum[i]));
    //     ans%=M;
    // }

    int sq_sum = 0;
    for(int i=1; i<=n; i++){
        sq_sum += (a[i]*a[i])%M;
        sq_sum %= M;
    }
    ans = (C(n-2, k-1) * (sq_sum)%M + (C(n-2,k-2) * (sum[n]%M*(sum[n]%M)%M)%M)%M)%M;
    
    cout << ans << '\n';
    
    
}