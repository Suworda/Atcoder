#include <iostream>
using namespace std;
int main() {
	bool ans=true;
	int dr[]={1,0,-1,0};
	int dc[]={0,1,0,-1};
	int h,w;
	cin>>h>>w;
	char a[h+2][w+2];
	for(int i=0; i<h+2; i++){
		a[i][0]='.';
		a[i][w+1]='.';
	}
	for(int i=0; i<w+2; i++){
		a[0][i]='.';
		a[h+1][i]='.';
	}
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(a[i][j]=='#'){
				int cnt=0;
				for(int k=0 ;k<4; k++){
					if(a[i+dr[k]][j+dc[k]]=='#'){
						cnt++;
					}
				}
				if(cnt==0 || cnt==1 || cnt==3) ans=false;
			}
		}
	}
	if(ans){
		cout<<"Yes\n"<<'\n';
	}else{
		cout<<"No\n";
	}
}
	
	