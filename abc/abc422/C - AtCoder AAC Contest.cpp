#include <iostream>
using namespace std;
int main() {
	long long t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		long long tot=a+b+c;
		cout<<min(min(a,c) , tot/3)<<'\n';
	}
}
