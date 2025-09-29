#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	queue<int> que;
	que.push(k);
	int N=1;
	for(int i=0; i<n; i++) N*=2;
	
	cout<<(k%N>=1)<<'\n';
	while(que.size()!=N){
		int x=que.front();
		que.pop();
		que.push(x/2);
		que.push((x+1)/2);
	}
	while(!que.empty()){
		cout<<que.front()<<' ';
		que.pop();
	}
	cout<<'\n';
	
}
