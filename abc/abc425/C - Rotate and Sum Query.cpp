#include <iostream>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,q;
	cin>>n>>q;
	int a[n+1];
	long long sum[n+1]={};
	for(int i=1; i<=n; i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	
	int d=0;
	while(q--){
		int ty,c,l,r,ans=0;
		cin>>ty;
		if(ty==1){
			cin>>c;
			d+=c;
			d%=n;
		}else{
			cin>>l>>r;
			l+=d-1; r+=d;
			if(l>n) l-=n;
			if(r>n) r-=n;
			
			if(l>=r){
				ans=sum[r]+sum[n]-sum[l];
			}else{
				ans=sum[r]-sum[l];
			}
			
			cout<<ans<<'\n';
		}
	}
}
