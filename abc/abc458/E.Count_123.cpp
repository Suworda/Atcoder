#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;
int a,b,c;
ll fact[3000005];

ll power(int a, int b){
    if(b == 0) return 1;
    ll m = power(a,b/2);
    if(b%2 == 0) return m*m%M;
    else return m*m%M*a%M;
}

ll inv(int x){
    return power(x,M-2);
}

ll C(int n, int m){
    if(n < m || n < 0 || m < 0) return 0;
    return fact[n] * inv(fact[n-m]) %M * inv(fact[m]) %M;
    // return 0;
}

ll H(int n, int m){
    return C(n+m-1, m);
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    fact[0] = 1;
    for(int i=1; i<=3000000; i++) fact[i] = fact[i-1] * i % M;
    cin>>a>>b>>c;

    ll ans = 0;
    for(int i=1; i<=b; i++){
        ans += C(b+1,i) * H(i,a-i)%M * H(b+1-i, c)%M;
        ans %= M;
    }

    cout<<ans<<'\n';
    
    
}
