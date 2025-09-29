#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(int i=0; i<n; i++){
			cin>>a[i];
	}
	for(int j=0; j<m; j++){
		cin>>b[j];
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(a[j]==b[i]){
				a[j]=-1;
				break;
			}
		}
	}
	
	for(int x: a){
		if(x!=-1)cout<<x<<' ';
	}
	cout<<'\n';
}
