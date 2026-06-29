#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dp[300005][12];
int vis[300005][12];
string s;
int K;
int T;

int f(int n, int k){
    if(vis[n][k] == T) return dp[n][k];
    if(k == 0) return 0;
    if(k > K || n<3) return 2e9;
    
    int rst = 2e9;
    
    if(s.substr(n-2, 3) == "ABC"){
        rst = min(rst, f(n-1, k+1));
        
    }else{
        rst = min(rst, f(n-1, k));
    }
    
    if(n-2 > 0 && s.substr(n-2, 3) == "ABC" || (n-3 > 0 && s.substr(n-3, 3) == "ABC") || (n-4 > 0 && s.substr(n-4, 3) == "ABC")){
        rst = min(rst, f(n-3, k) + (s[n-2] != 'A') + (s[n-1] != 'B') + (s[n] != 'C'));
        
    }else{
        rst = min(rst, f(n-3, k-1) + (s[n-2] != 'A') + (s[n-1] != 'B') + (s[n] != 'C'));
    }
    
    
    
    // cerr<<n<<' '<<k<<':';
    // cerr<<rst<<'\n';
    vis[n][k] = T;
    return dp[n][k] = rst;

    
}

void sol(){
    T++;
    cin>>s>>K;
    s = ' ' + s;
    int ans = f(s.size()-1, K);
    cout << (ans < 2e9 ? ans : -1) << '\n';
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}