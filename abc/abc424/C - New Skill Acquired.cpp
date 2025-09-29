#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool t[200005]={};
set<int> v[200005];
int n;
int ans=0;
queue<int> q;

int main() {
	bool haveq[200005]={};
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	int a,b;
	for(int i=1; i<=n; i++){
		cin>>a>>b;
		v[a].insert(i);
		v[b].insert(i);
		
	}
	
	q.push(0);
	int x;
	while(!q.empty()){
		x=q.front();
		q.pop();
		t[x]=true;
		for(auto y:v[x]){
			if(!t[y] && !haveq[y]){
				q.push(y);
				haveq[y]=true;
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		ans+=(t[i]);
	}
	
	cout<<ans<<'\n';
}
