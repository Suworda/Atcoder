#include <iostream>
using namespace std;
int main() {
	int a,b;
	char c;
	cin>>a>>c>>b;
	if(b==8){
		a++;
		b=0;
	}
	b++;
	cout<<a<<c<<b<<'\n';
}
