#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

pair<int,int> exgcd(int a, int b){
    if(b == 0) return {a >= 0 ? 1 : -1, 0}; //
    auto [x, y] = exgcd(b, a%b);
    return {y, x - a/b * y};
}

optional<pair<int,int>> exgcd(int a, int b, int c){
    if(a == 0 && b == 0){
        if(c == 0) return pair<int,int> {0, 0};
        else return nullopt;
    }

    int g = gcd(a, b);
    if(c % g != 0) return nullopt;

    auto [x, y] = exgcd(a, b);
    
    return pair<int,int> {x*(c/g), y*(c/g)};

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, s, k;
        cin >> n >> s >> k;

        auto ans = exgcd(-k, n, s);

        int g = gcd(-k, n);

        int M = n/g;
        if(ans) cout << ((*ans).first % M + M) % M << '\n';
        else cout << -1 << '\n';
    }
    
}