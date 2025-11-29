#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001]={};
pair<int,int> source[3001][3001]={};
string path;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;

    for(int i=1; i<=s.size(); i++){
        for(int j=1; j<=t.size(); j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                source[i][j] = {i-1 , j-1};
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(dp[i][j-1] >= dp[i-1][j]){
                    source[i][j] = {i,j-1};
                }else{
                    source[i][j] = {i-1, j};
                }
            }
            
        }
    }

    int r=s.size(), c=t.size(); 
    while(r != 0 && c != 0){
        //cout<<r<<' '<<c<<'\n';
        if(s[r-1]==t[c-1]) path+=s[r-1];
        tie(r,c) = source[r][c];
    }
    reverse(path.begin(), path.end());
    cout<<path<<'\n';
}

