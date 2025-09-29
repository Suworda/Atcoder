#include <iostream>
using namespace std;
int main() {
	int h,w;
	cin>>h>>w;
	int a[h][w],p[h+w-1];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<h+w-1; i++){
		cin>>p[i];
	}
	long long ans[h][w]={};
	ans[h-1][w-1]=max(0,p[h+w-2]-a[h-1][w-1]);
	for(int i=h-1; i>=1; i--){
		ans[i-1][w-1]=max(ans[i][w-1]+p[i+w-2]-a[i-1][w-1],0LL);
	}
	for(int i=w-1; i>=1; i--){
		ans[h-1][i-1]=max(ans[h-1][i]+p[i+h-2]-a[h-1][i-1],0LL);
	}
	
	for(int i=h-2; i>=0; i--){
		for(int j=w-2; j>=0; j--){
			ans[i][j]=max(min(ans[i+1][j],ans[i][j+1])+p[i+j]-a[i][j],0LL);
		}
	}
	
	cout<<max(ans[0][0],0LL)<<'\n';
//	for(int i=0; i<h; i++){
//		for(int j=0; j<w; j++){
//			cout<<ans[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	
}
