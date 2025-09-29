#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

bool cmp(int x, int y){
	if(abs(x)<abs(y)){
		return true;
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		set<int> s;
		bool ans=true;
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
			s.insert(a[i]);
		} 
		if(s.size()==2){
			int x=a[0],y;
			int cntx=0,cnty=0;
			for(int i=0; i<n; i++){
				if(a[i]==x){
					cntx++;
				}else{
					y=a[i];
					cnty++;
				}
			}
			if(x==-y && abs(cntx-cnty)<=1){
				cout<<"Yes\n";
				continue;
			}
		}  
		
		sort(a,a+n,cmp);
		for(int i=0; i<n-2; i++){
			if(a[i]*a[i+2]!=a[i+1]*a[i+1]){
				ans=false;
			}
		}
		if(ans){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
}
/*
4
5
1 8 2 4 16
5
-16 24 54 81 -36
7
90000 8100 -27000 729 -300000 -2430 1000000
7
1 1 1 -1 -1 -1 1


1
6
-1 1 -1 1 -1 -1
*/