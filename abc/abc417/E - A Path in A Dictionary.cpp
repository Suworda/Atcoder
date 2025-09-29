#include <iostream>
#include <set>
#include <vector>
using namespace std;

int y;
int tcnt=0;
int path[1002];
int vis[1002];
int cnt;
vector<set<int>> s;

bool dfs(int cur, int th){
	path[th]=cur;
	if(cur==y){
		cnt=th;
		return true;
	}
	for(auto next:s[cur]){
		if(vis[next]!=tcnt){
			vis[next]=tcnt;
			if(dfs(next,th+1))return true;	
			//vis[next]=0;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	int n,m,x,u,v;
	while(t--){
		tcnt++;
		cin>>n>>m>>x>>y;
		s.clear();
		s.resize(n+1);
		while(m--){
			cin>>u>>v;
			s[u].insert(v);
			s[v].insert(u);
		}
		vis[x]=tcnt;
		dfs(x,0);
		
		for(int i=0; i<=cnt; i++){
			cout<<path[i]<<' ';
		}
		cout<<'\n';
	}
}
