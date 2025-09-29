#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long ans=0;
		int n,m;
		cin>>n>>m;
		int a[n],b[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
			ans+=a[i];
		}
		for(int i=0; i<n; i++){
			cin>>b[i];
			ans+=b[i];
		}
		sort(a,a+n); 
		sort(b,b+n, greater<int>());
		
		int x=0,y=0;
		while(x<n && y<n){
			if(a[x]+b[y]<m){
				x++;
			}else{
				ans-=m;
				x++; y++;
			}
		}
		cout<<ans<<"\n";
		
	}
}
