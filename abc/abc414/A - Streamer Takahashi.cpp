#include <iostream>
using namespace std;
int main() {
	int n,l,r;
	cin>>n>>l>>r;
	int ans=0;
	while(n--){
		int x,y;
		cin>>x>>y;
		if(x<=l && y>=r){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
