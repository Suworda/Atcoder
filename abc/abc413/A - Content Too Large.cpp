#include <iostream>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	int cur=0;
	while(n--){
		int x;
		cin>>x;
		cur+=x;
	}
	if(cur<=m){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
}
