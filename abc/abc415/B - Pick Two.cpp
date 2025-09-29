#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s;
	cin>>s;
	vector<int> ans;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='#'){
			ans.push_back(i+1);
		}
	}
	int i=0;
	while(i<ans.size()-1){
		cout<<ans[i]<<","<<ans[i+1]<<"\n";
		i+=2;
	}
}
