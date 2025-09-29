#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		bitset<(1<<18)> dp;
		dp[0]=true;
		for(int i=0; i<(1<<n); i++){
			if(dp[i]){
				for(int j=0; j<n; j++){
					int next=( i | (1<<j));
					if(s[next-1]=='0'){
						dp[next]=true;
					}
				}
			}
		}
//		for(int i=0; i<(1<<n); i++){
//			cout<<dp[i];
//		}	
		if(dp[(1<<n)-1]){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		
	}
}
