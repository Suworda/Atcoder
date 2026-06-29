#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;
vector<int> x,y;
ll dp[200005][2];

void sol(){
    x.clear();
    y.clear();

    cin>>n>>s;
    s = ' ' + s;
    x.resize(n+1);
    y.resize(n);
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    for(int i=1; i<=n-1; i++){
        cin>>y[i];
    }

    for(int i=1; i<=n; i++){
        // case1: R
        if(s[i] == 'S'){
            dp[i][0] = -x[i]+max(dp[i-1][0], dp[i-1][1]);
            
        }else{
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }

        //case2: S
        if(s[i] == 'R'){
            dp[i][1] = -x[i]+max(dp[i-1][0] + y[i-1], dp[i-1][1]);
            
        }else{
            dp[i][1] = max(dp[i-1][0] + y[i-1], dp[i-1][1]);
        }
        
        
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}