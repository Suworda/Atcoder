#include <iostream>
using namespace std;
#define int long long

struct Move{
    char c;
    int x;
};

struct Point{
    int r,c;
};

Point d[128];

signed main(){
    d['U']={0,-1}; d['D']={0,1}; d['L']={-1,0}; d['R']={1,0};
    
    int ar,ac,br,bc;
    cin>>ac>>ar>>bc>>br;
    long long n,m,l,ans=0;
    cin>>n>>m>>l;
    
    Move a[m] ,b[l];
    for(int i=0; i<m; i++){
        cin>>a[i].c>>a[i].x;
    }
    for(int i=0; i<l; i++){
        cin>>b[i].c>>b[i].x;
    }
    
    int ai=0, bi=0,y,test;
    while(n){
        // cout<<ar<<' '<<ac<<' '<<br<<' '<<bc<<'\n';
        if(a[ai].x==0) ai++;
        if(b[bi].x==0) bi++;
        
        if(ar==br && ac==bc){
            y=min(a[ai].x,b[bi].x);
            if(a[ai].c==b[bi].c){
                ans+=y;
            }
            a[ai].x-=y; b[bi].x-=y;
            ar+=(d[a[ai].c].r)*y; 
            ac+=(d[a[ai].c].c)*y; 
            br+=(d[b[bi].c].r)*y; 
            bc+=(d[b[bi].c].c)*y; 
            n-=y;
        
        }else if(ar==br && abs(a[ai].c-b[bi].c)=='U'-'D'){
            int dc=(abs(bc-ac)+1)/2;
            dc=min(dc,min(a[ai].x,b[bi].x));
            a[ai].x-=dc; b[bi].x-=dc;
            ac+=(d[a[ai].c].c)*dc;
            bc+=(d[b[bi].c].c)*dc; 
            if(ac==bc) ans++;
            n-=dc;
            
        }else if(ac==bc && abs(a[ai].c-b[bi].c)=='R'-'L'){
            int dr=(abs(br-ar)+1)/2;
            dr=min(dr,min(a[ai].x,b[bi].x));
            a[ai].x-=dr; b[bi].x-=dr;
            
            ar+=(d[a[ai].c].r)*dr;
            br+=(d[b[bi].c].r)*dr; 
            if(ar==br) ans++;
            n-=dr;
            
        }else{
        	if(abs(ar-br)==abs(ac-bc)){
	            y=min(abs(ar-br), min(a[ai].x , b[bi].x));
	            a[ai].x-=y; b[bi].x-=y;
        		ar+=(d[a[ai].c].r)*y; 
	            ac+=(d[a[ai].c].c)*y; 
	            br+=(d[b[bi].c].r)*y; 
	            bc+=(d[b[bi].c].c)*y;
	            n-=y;
	            if(ar==br && ac==bc) ans++;
				 
			}else{
	            y=min(a[ai].x,b[bi].x);
	            a[ai].x-=y; b[bi].x-=y;
	            
	            ar+=(d[a[ai].c].r)*y; 
	            ac+=(d[a[ai].c].c)*y; 
	            br+=(d[b[bi].c].r)*y; 
	            bc+=(d[b[bi].c].c)*y; 
	            n-=y;
	            if(ar==br && ac==bc) ans++;
			}
			
            
        }
    }
    
    cout<<ans<<'\n';
    
    
    
    
}



