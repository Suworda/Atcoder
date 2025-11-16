#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001]={};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;

    for(int i=1; i<=s.size(); i++){
        for(int j=1; j<=t.size(); j++){
            if(s[i-1][j-1]==t[i-1][j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            }
        }
    }
}

