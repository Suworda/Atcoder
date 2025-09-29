#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	long long p[n],dis[n-1],tot=0;
	for(int i=0; i<n; i++){
		cin>>p[i];
	}
	
	sort(p,p+n);
	tot=p[n-1]-p[0];
	for(int i=0; i<n-1; i++){
		dis[i]=p[i+1]-p[i];
	}
	sort(dis,dis+n-1);
	for(int i=0; i<m-1; i++){
		tot-=dis[n-2-i];
	}
	cout<<tot<<"\n";
	
	
	
}
