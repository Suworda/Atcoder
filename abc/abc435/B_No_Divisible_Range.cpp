#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans=0;
    for(int l=0; l<n; l++){
        for(int r=l+1; r<n; r++){
            int tot=0;
            for(int i=l; i<=r; i++){
                tot+=a[i];
            }
            bool ok=true;
            for(int i=l; i<=r; i++){
                if(tot%a[i]==0) ok=false;
            }
            ans += ok;
        }
    }

    cout<<ans<<'\n';

}