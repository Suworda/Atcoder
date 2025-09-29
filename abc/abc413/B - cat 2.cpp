#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	int n;
	cin>>n;
	set<string> ans;
	string s[n+1];
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i!=j) ans.insert(s[i]+s[j]);
		}
	}
	cout<<ans.size()<<"\n";
}
