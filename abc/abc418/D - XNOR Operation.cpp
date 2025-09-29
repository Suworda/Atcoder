#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	string s;
	cin>>n>>s;
	int dp[n+1][2]={};
	dp[0][s[0]=='0']=1;
	for(int i=1; i<s.size(); i++){
		if(s[i]=='0'){
			dp[i][0]=dp[i-1][1]; 
			dp[i][1]=dp[i-1][0]+1;
		}else{ //=='1'
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1];
		}
	}
	long long ans=0;
	for(int i=0; i<n; i++) ans+=dp[i][0];
	
	cout<<ans<<'\n';
}
