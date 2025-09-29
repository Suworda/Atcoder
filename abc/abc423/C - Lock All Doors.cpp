#include <iostream>
using namespace std;

int main(){
    int n,R;
    cin>>n>>R;
    int d[n];
    int sum[n+1];
    sum[0]=0;
    for(int i=1; i<=n; i++){
        cin>>d[i];
        sum[i]=sum[i-1]+d[i];
    }
    
    if(sum[n]==n){
        cout<<0<<'\n';
        return 0;
    }
    
    int l=1,r=1;
    for(int i=1; i<=n; i++){
        if(d[i]==0){
            l=i;
            break;
        }
    }
    for(int i=n; i>=1; i--){
        if(d[i]==0){
            r=i;
            break;
        }
    }
    
    int ans=r-l+1+sum[r]-sum[l-1];
    
    if(R>r){
        ans+=(R-r)+sum[R]-sum[r];
    }
    
    if(R<l-1){
        ans+=(l-R-1)+sum[l]-sum[R];
    }
    
    cout<<ans<<'\n';
    
}

/*
8 0
1 1 0 0 1 0 1 1

8 0
1 1 1 1 1 1 1 1

*/

