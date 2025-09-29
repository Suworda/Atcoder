#include <iostream>
#include <string>
#define int long long
using namespace std;
int a[200005],b[200005];
int minv[200005];
// int cnt=0;
int cur=0;

void sol(){ 
    char c;
    int x,v;
    cin>>c>>x>>v;
    x--;
    if(c=='A'){
        // if(v<minv[x]){
        //     cur-=(minv[x]-v);
        //     minv[x]=v;
        //     a[x]=v;
        // }else if(v==minv){
        //     if(v>minv[x] && )
        // }else{
        cur-=minv[x];
        a[x]=v;
        minv[x]=min(a[x],b[x]);
        cur+=minv[x];
        // }
        
    }else{
        cur-=minv[x];
        b[x]=v;
        minv[x]=min(a[x],b[x]);
        cur+=minv[x];
    }
    // if(v<minv){
    //     cnt=1;
    // }else if(v==minv){
    //     cnt++;
    // }
    // minv=min(v,minv);
    
    cout<<cur<<'\n';
    
}

signed main() {
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>a[i];
        // if(a[i]<minv){
        //     cnt=1;
        // }else if(a[i]==minv){
        //     cnt++;
        // }
        // minv=min(a[i],minv);
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        // if(b[i]<minv){
        //     cnt=1;
        // }else if(b[i]==minv){
        //     cnt++;
        // }
        // minv=min(b[i],minv);
    }
    
    for(int i=0; i<n; i++){
        minv[i]=min(a[i],b[i]);
        cur+=minv[i];
    }
    // cout<<cur;
    while(q--) sol();
}