#include <iostream>
using namespace std;
int main() {
	int n,x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cin>>x;
	bool ans=false;
	for(int i=0; i<n; i++){
		if(a[i]==x){
			ans=true;
		}
	}
	if(ans){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
}
