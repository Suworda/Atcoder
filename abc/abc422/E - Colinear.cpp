#include <iostream>
#include <random>
#include <numeric>
using namespace std;
//-100 -101 7395945187
int main() {
//	long long g=gcd(gcd(4655800,4702358),-344340416016346);
//	cout<<4655800/g<<' '<<4702358/g<<' '<<-344340416016346/g;
	int n;
	cin>>n;
	long long x[n],y[n];
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	mt19937 gen;
	
	for(int t=0; t<100; t++){
		int i,j;
		
		do{
			i=gen()%n;
			j=gen()%n;
		}while(i==j);
		
		long long a=y[j]-y[i], b=x[i]-x[j], c=x[j]*y[i] - x[i]*y[j];
		
		int cnt=0;
		for(int k=0; k<n; k++){
			if(a*x[k] + b*y[k] + c == 0) cnt++;
		}
		
		if(cnt>n/2){
			cout<<"Yes\n";
			cout<<a<<' '<<b<<' '<<c<<'\n';
			return 0;
		}
		
	}
	cout<<"No\n";
	
}
