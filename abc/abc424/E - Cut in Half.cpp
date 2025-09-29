#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct Stick{
	double len;
	int cnt;
	
	bool operator < (const Stick &b) const{
		return len<b.len;
	} 
};

int main() {
	int t;
	cin>>t;
	while(t--){
		priority_queue<Stick> pq;
		Stick cur;
		int n,k,x;
		cin>>n>>k>>x;
		double a;
		for(int i=0; i<n; i++){
			cin>>a;
			pq.push({a,1});
		}
		
		
		while(k>pq.top().cnt){
			cur=pq.top();
			pq.pop();
			k-=cur.cnt;
			pq.push({cur.len/2 , cur.cnt*2});
		}
		
		cur=pq.top();
		pq.pop();
		pq.push({cur.len, cur.cnt-k});
		pq.push({cur.len/2, k*2});
		
		
		while(x>pq.top().cnt){
			x-=pq.top().cnt;
			pq.pop();
		}
		
//		while(!pq.empty()){
//			cout<<pq.top().len<<' '<<pq.top().cnt<<'\n';
//			pq.pop();
		
		cout<<fixed<<setprecision(15)<<pq.top().len<<'\n';
		
	}
}
