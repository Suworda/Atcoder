#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int p = 998244353;

int power(int a, int b, int M){
    if(b == 0) return 1%M;
    a %= M;

    int m = power(a, b/2, M);
    if(b & 1) return m*m%M*a%M;
    else return m*m%M;
}

void print(int a, int b, int c){
    if(a % p == 0) cout << 0 << '\n';
    else cout << power(a, power(b, c, p-1), p) << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, a;
    cin >> n >> k >> a;

    print(a, k, n);
    
}