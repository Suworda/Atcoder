#include <iostream>
#include <vector>
using namespace std;
int n,q;
bool black[200005];
int parent[200005];
int cnt[200005];
int cur[200005];

int find(int x){
	if(parent[x]==x){
		return x;
	}
	
	return parent[x]=find(parent[x]);
}

void merge(int a, int b){
	int x=find(a) ,y=find(b);
	if(x==y) return;
	parent[y]=x;
	cnt[x]+=cnt[y];
}

void sol(){
    int ty,u,v;
    cin>>ty;
    
    
    if(ty==1){ //connect
        cin>>u>>v;
        merge(u,v);
        
        
        
    }else if(ty==2){ //change
        cin>>v;
        if(black[v]) cnt[find(v)]--;
        else cnt[find(v)]++;
        black[v]=!black[v];
        
    }else{ //yes or no
    	cin>>v;
        if(cnt[find(v)]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
        
    }
    
//    for(int i=1; i<=5; i++) cout<<i<<':'<<find(i)<<' '<<cnt[find(i)]<<'\n';
    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<=n; i++){
        cur[i]=i;
        parent[i]=i;
    }
    while(q--) sol();
}




