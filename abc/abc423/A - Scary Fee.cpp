#include <iostream>
using namespace std;

int main(){
    int x,c;
    cin>>x>>c;
    int ans=x/1000*1000;
    while(ans+ans/1000*c>x && ans){
        ans-=1000;
    }
    
    cout<<ans<<'\n';
    
}