#include <iostream>
using namespace std;

int main(){
    int s,a,b,x;
    cin>>s>>a>>b>>x;
    long long ans=0;
    while(x>0){
        ans+=s*min(x,a);
        x-=a+b;

    }

    cout<<ans<<'\n';
}
