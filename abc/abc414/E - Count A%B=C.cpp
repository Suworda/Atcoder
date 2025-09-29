#include <iostream>
#include <cmath>
using namespace std;
int main() {
	const long long M=998244353;
	long long n,ans=0;
	cin>>n;
	long long x=0;
	long long k=sqrt(n);
	for(long long i=1; i<=k; i++){
		x+=n/i;
		x%=M;
	}
	ans=(n%M)*(n%M)-(2*x-k*k)-(n%M*((n+1)%M))/2+n;
	cout<<ans%M<<"\n";
	
	
		
}
/*
411111111114
*/
