#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;

int n;
string s;
ll dp[4];
ll ans;
vector<pair<int,int>> v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s;
    n = s.size();
    s = ' ' + s;
    dp[0] = 1;

    int cur = 1;
    for(int i=1; i<=n; i++){
        int ty = s[i] - 'a' + 1;
        for(int i=0; i<=3; i++){
            if(i != ty) dp[ty] += dp[i];
            dp[ty]%=M;
        }
        
        dp[ty] %= M;
    }
    cout<<(dp[1] + dp[2] + dp[3])%M<<'\n';
}
