#include <iostream>
#include <string>
#include <algorithm>
//#define int long long
using namespace std;
int a;

bool also(long long x){
	string s;
	while(x>0){
		s+=to_string(x%a);
		x/=a;
	}
	int l=0, r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			return false;
		}
		l++; r--;
	}
	return true;
}

signed main() {
	long long n,ans=0;
	cin>>a>>n;
//	for(int i=1; i<=9; i++){
//		if(i!=a){
//			ans+=i;
//		}
//	}
	
	for(int i=1; i<10000000; i++){
		string s=to_string(i);
		for(int j=s.size()-2; j>=0; j--){
			s+=s[j];
		}
		long long cur=stoll(s);
		
		if(cur>n){
			break;
		}
		
//		cout<<cur<<"\n";
		if(also(cur)){
//			cout<<cur<<"\n";
			ans+=cur;
		}
		
	}for(int i=1; i<10000000; i++){
		string s=to_string(i);
		for(int j=s.size()-1; j>=0; j--){
			s+=s[j];
		}
		long long cur=stoll(s);
		
		if(cur>n){
			break;
		}
		
//			cout<<cur<<"\n";
		if(also(cur)){
//			cout<<cur<<"\n";
			ans+=cur;
		}
	}
	
	cout<<ans<<"\n";
}
