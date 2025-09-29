#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,k,x;
	cin>>n>>k>>x;
	vector<string> ans;
	string s[n];
	int d[k+1]={};
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	while(d[k]==0){
		string cur;
		for(int i=0; i<k; i++){
			cur+=s[d[i]];
		}
		ans.push_back(cur);
		d[0]++;
		for(int i=0; i<k; i++){
			if(d[i]>=n){
				d[i+1]++;
				d[i]=0;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans[x-1]<<'\n';
}
