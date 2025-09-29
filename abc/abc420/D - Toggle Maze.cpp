#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int h,w;
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};

int step[2][505][505];
char a[2][505][505];
bool vis[2][505][505];
queue<tuple<int,int,int>> que; 

int main(){
	cin>>h>>w;
	for(int i=0; i<=h+1; i++){
		a[0][i][0]='#';
		a[0][i][w+1]='#';
		a[1][i][0]='#';
		a[1][i][w+1]='#';
	}
	for(int i=0; i<=w+1; i++){
		a[0][0][i]='#';
		a[0][h+1][i]='#';
		a[1][0][i]='#';
		a[1][h+1][i]='#';
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cin>>a[0][i][j];
			if(a[0][i][j]=='o'){
				a[1][i][j]='x';
			}else if(a[0][i][j]=='x'){
				a[1][i][j]='o';
			}else if(a[0][i][j]=='S'){
				a[1][i][j]='.';
				que.push({0,i,j});
			}else{
				a[1][i][j]=a[0][i][j];
			}
		}
	}
	
//	for(int i=0; i<=h+1; i++){
//		for(int j=0; j<=w+1; j++){
//			cout<<a[1][i][j];
//		}
//		cout<<'\n';
//	}
	
	int nty,nr,nc;
	while(!que.empty()){
		auto [ty,r,c]=que.front();
//		cout<<r<<' '<<c<<'\n';
		if(a[ty][r][c]=='G'){
			cout<<step[ty][r][c]<<'\n';
			return 0;
		}
		que.pop();
		for(int i=0; i<4; i++){
			nr=r+dr[i];
			nc=c+dc[i];
			if(a[ty][nr][nc]=='?'){
				nty=!ty;
			}else{
				nty=ty;
			}
			if(a[nty][nr][nc]!='#' && a[nty][nr][nc]!='x' && !vis[nty][nr][nc]){
				que.push({nty, nr, nc});
				step[nty][nr][nc]=step[ty][r][c]+1;
				vis[nty][nr][nc]=true;
			}
		}
		
	}
	
	cout<<-1<<'\n';
	
}