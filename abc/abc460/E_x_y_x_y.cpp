#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define ll unsigned long long

const int M = 998244353;
int t;
int n,m;

ll pow_10(int b){
    ll rst = 1;
    while(b--){
        rst *= 10;
    }
    return rst;
}

// ll concat(int x, int y){
//     string a = to_string(x);
//     string b = to_string(y);

//     string c = a + b;
//     return stoll(c)%M;
// }

ll calc(int k){
    ll x = pow_10(k)-1;
    ll y = pow_10(k-1)-1;
    int g = gcd(m,x);
    return n/(m/g)%M*((min(x,n)-y)%M);
}

void sol(){
    cin>>n>>m;
    ll ans = 0;
    int k = to_string(n).size();
    for(int i=1; i<=k ; i++){
        ans += calc(i)%M;
        ans%=M;
        // cout<<ans<<' ';
    }
    
    cout<<ans%M<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t--) sol();

}

// for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//         // cout<<concat(i,j)<<' '<<i+j<<'\n';
//         if(concat(i,j)%m == (i+j)%m){
//             ans++;
//             // cout<<i<<' '<<j<<'\n';
//         }
//     }
// }