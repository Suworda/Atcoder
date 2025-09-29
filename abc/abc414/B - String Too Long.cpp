#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin>>n;
	string s;
	bool ok=true;
	while(n--){
		char c;
		long long int l;
		cin>>c>>l;
		if(l+s.size()>100){
			cout<<"Too Long\n";
			ok=false;
			break;
		}else{
			while(l--){
				s+=c;
			}
		}
		
	}
	if(ok){
		cout<<s<<"\n";
	}
	
}
/*
3
a 1
b 1
c 1
*/