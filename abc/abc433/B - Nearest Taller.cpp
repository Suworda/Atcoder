#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        int ans=-1;
        for(int j=i-1; j>=0; j--){
            if(a[i]<a[j]){
                ans=j+1;
                break;
            }
        }

        if(ans!=-1) cout<<ans<<'\n';
        else cout<<-1<<'\n';


    }


}
