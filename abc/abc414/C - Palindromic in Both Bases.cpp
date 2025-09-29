 #include <iostream>
 #include <string>
using namespace std;

bool ok(string cur){
	for(int j=0; j<cur.size()/2; j++){
		if(cur[j]!=cur[cur.size()-1-j]){
			return false;
		}
	}
	return true;
}

string change(int a, long long n){
	string ans;
	while(n){
		ans+=(n%a + '0');
		n/=a;
	}
	return ans;	
	
}

int main() {
	int test=10;
	while(test--){
		int a;
		long long n;
		string sn;
		cin>>a>>n;
		long long int x=1,y=1;
		while(x<=n){
			string cur=change(10,x);
//			if(ok(cur)){
				if(ok(change(a,x))){
					cout<<x<<" ";
					cout<<change(a,x)<<"\n";
				}
//				cout<<x<<"\n";
//			}
//			if((x+1)%10==0){
//				x+=2;
//			}
			x++;
		}
		cout<<"\n";
		
//		for(long long int i=1; i<=n; i++){
//			string cur=change(10,i);
//			if(ok(cur)){
//				cout<<i<<"\n";
//				if(ok(change(a,i))){
//					cout<<i<<"\n";
////				}
//			}
//			
//		}
	}
//	n=stoi(sn);
//	cout<<change(a,n)<<"\n";
//	for(int i=0; i<sn.size()/2; i++){
//		if(sn[i]!=sn[sn.size()-1-i]){
//			
//		}
//	}
}
/*
2
50000
3
50000
4
50000
5
50000
6
50000
7
50000
8
50000
9
50000


*/
