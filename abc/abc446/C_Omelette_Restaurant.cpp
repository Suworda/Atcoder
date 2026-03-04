#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,d;
    cin>>n>>d;
    int a[n+1]={};
    int b[n+1]={};
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    int id=1;
    for(int i=1; i<=n; i++){
        int x = b[i];
        while(x > 0){
            if(x < a[id]){
                a[id] -= x;
                x=0;
            }else{
                x -= a[id];
                a[id++] = 0;
            }
        }
        if(i-d > 0) a[i-d]=0;
        
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=a[i];
    }

    cout<<ans<<'\n';
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    
}
