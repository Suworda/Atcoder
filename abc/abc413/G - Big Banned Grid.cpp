#include <iostream>
#include <unordered_set>
using namespace std;

struct Hash {
	size_t operator()(const pair<int,int> x) const{
		return (long long)x.first*200000+x.second;
	}
};

const int Left=0, Right=1, up=2, down=3;
//string name[]={Left}

int main() {
	unordered_set<pair<int,int>,Hash> obs;
	int h,w,k;
	cin>>h>>w>>k;
	int r,c;
	for(int i=0; i<k; i++){
		cin>>r>>c;
		obs.insert({r,c});
	}
	for(int r=0; r<=h+1; r++){
		obs.insert({r,0});
		obs.insert({r,w+1});
	}
	for(int c=0; c<=w+1; c++){
		obs.insert({0,c});
		obs.insert({h+1,c});
	}
//	
	int curr=1,curc=1,dir=Left;
	while(true){
//		cout<<curr<<" "<<curc<<" "<<dir<<"\n";
		if(dir==Left){
			if(obs.count({curr+1,curc})){
				dir=down;
				
			}else{
				if(obs.count({curr+1,curc-1})){
					curr++;
					
				}else{
					curr++;
					curc--;
					dir=up;
					
				}
			}
			
		}else if(dir==down){
			if(obs.count({curr,curc+1})){
				dir=Right;
				
			}else{
				if(obs.count({curr+1,curc+1})){
					curc++;
					
				}else{
					curr++;
					curc++;
					dir=Left;
					
				}
			}
			
		}else if(dir==Right){
			if(obs.count({curr-1,curc})){
				dir=up;
				
			}else{
				if(obs.count({curr-1,curc+1})){
					curr--;
					
				}else{
					curr--;
					curc++;
					dir=down;
					
				}
			}
		}else{ // up
			if(obs.count({curr,curc-1})){
				dir=Left;
				
			}else{
				if(obs.count({curr-1,curc-1})){
					curc--;
					
				}else{
					curr--;
					curc--;
					dir=Right;
					
				}
			}
		}
		if(curr==1 && curc==1 && dir==up){
			cout<<"No\n";
			break;
		}else if(curr==h && curc==w){
			cout<<"Yes\n";
			break;
		}
		
	}
	
}
