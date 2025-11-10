#include <iostream>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;
    r=min(r,l+2019);
    int ans=2e9;
    for(int i=l; i<r; i++){
        for(int j=i+1; j<=r; j++){
            ans=min(ans, (i%2019)*(j%2019)%2019);
        }
    }

    cout<<ans<<'\n';
}
