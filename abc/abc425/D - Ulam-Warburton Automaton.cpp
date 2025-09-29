#include <iostream>
#include <queue>
using namespace std;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
int h,w;

bool ok(int r, int c){
	return (r>=1 && r<=h && c>=1 && c<=w);
}

int main() {
	int ans=0;
	queue<pair<int,int>> que;
	cin>>h>>w;
	bool a[h+5][w+5]={};
	char c;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cin>>c;
			if(c=='#'){
//				ans++;
				a[i][j]='#';
				for(int k=0; k<4; k++){
					if(ok(i+dr[k] , j+dc[k])) que.push({i+dr[k] , j+dc[k]});
				}
			}
		}
	}
	
	while(!que.empty()){
		pair<int,int> cur=que.front();
		int i=cur.first;
		int j=cur.second;
		que.pop();
		if(a[i][j]) continue;
		int cnt=0;
		
		for(int k=0; k<4; k++){
			if(ok(i+dr[k] , j+dc[k])) cnt+=a[i+dr[k]][j+dc[k]];
		}
		
		if(cnt==1){
			a[i][j]=true;
			for(int k=0; k<4; k++){
				if(ok(i+dr[k] , j+dc[k])) que.push({i+dr[k] , j+dc[k]});
			}
		}
	}
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			int cnt=0;
			for(int k=0; k<4; k++){
				if(ok(i+dr[k] , j+dc[k])) cnt+=a[i+dr[k]][j+dc[k]];
			}
		
			if(cnt==1){
				a[i][j]=true;
				for(int k=0; k<4; k++){
					if(ok(i+dr[k] , j+dc[k])) que.push({i+dr[k] , j+dc[k]});
				}
			}
		}
	}
	
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cout<<a[i][j];
			ans+=a[i][j];
		}
		cout<<'\n';
	}
	
	cout<<ans<<'\n';
	
}
