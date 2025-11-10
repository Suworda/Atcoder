#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans=2e9;

    for(int i=0; i<(1 << n); i++){
        int cur=0;
        int x=a[0];
        for(int j=1; j<n; j++){
            if(((i >> j) & 1) == ((i >> j-1) & 1)) x|=a[j];
            else{
                cur^=x;
                x=a[j];
            }
        }
        //cout<<x[0]<<' '<<x[1]<<'\n';
        ans=min(ans, cur^x);
    }

    cout<<ans<<'\n';
}
