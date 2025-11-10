#include <iostream>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    int w[n+1];
    for(int i=1; i<=n; i++) cin>>w[i];

    int q;
    cin>>q;
    int p;
    while(q--){
        cin>>p;
        x+=w[p];
        w[p]*=-1;
        cout<<x<<'\n';
    }
}
