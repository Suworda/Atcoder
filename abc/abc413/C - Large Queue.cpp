#include <iostream>
#include <queue>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	queue<pair<int,int>> A;
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int c,x;
			cin>>c>>x;
			A.push({x,c});
			
		}else{
			int k;
			cin>>k;
			long long int ans=0;
			while(k>0){
				if(k>A.front().second){
					ans+=((long long)A.front().first * A.front().second);
					k-=A.front().second;
					A.pop();
					
				}else{
					ans+=((long long)A.front().first * k);
					A.front().second-=k;
					break;
				}
			}
			cout<<ans<<"\n";
			
		}
	}
}
/*
5
1 2 3
1 4 5
2 3
1 6 2
2 5
*/
