#include <iostream>
using namespace std;
int h,w;
bool a[9][9];
char c;

int dfs(int r, int c, int cnt){
	if(c==w+1){
		r++;
		c=1;
	}
	
	if(r==h-1 && c==w){
		return cnt;
	}
	
	bool found=false; //found white
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			if(a[r+i][c+j]==false) found=true;
		}
	}
	
	if(!found){
		a[r+1][c]=false;
		int x=dfs(r, c+1,cnt+1);
		a[r+1][c]=true;
		a[r+1][c+1]=false;
		int y=dfs(r, c+1,cnt+1);
		a[r+1][c+1]=true;
		return min(x,y);
	}else{
		return dfs(r, c+1,cnt);
	}
	
}

void sol(){
	cin>>h>>w;
	for(int i=0; i<=h+1; i++){
		for(int j=0; j<=w+1; j++){
			a[i][j]=false;
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cin>>c;
			a[i][j]=(c=='#');
		}
	}
	
	cout<<dfs(1,1,0)<<'\n';
	
}

int main() {
	int t;
	cin>>t;
	while(t--) sol();
}
