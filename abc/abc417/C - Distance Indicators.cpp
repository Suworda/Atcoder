#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n+1];
	unordered_map<int,int> b,c;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		b[a[i]+i]++;
		if(i-a[i]>0) c[i-a[i]]++;
	}
	long long ans=0;
	for(auto &x:b){
		//if(c.find(x.first)!=c.end()){
			ans+=(long long)x.second*c[x.first];
		//}
	}
	cout<<ans<<'\n';
}
