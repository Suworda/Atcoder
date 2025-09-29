#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> v[n+1];
	int a,b;
	for(int i=0; i<k; i++){
		cin>>a>>b;
		v[a].push_back(b);
		if(v[a].size()==m){
			cout<<a<<' ';
		}
	}
	cout<<'\n';
}
