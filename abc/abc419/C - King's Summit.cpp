#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, R, C, u=2147483647,d=0,r=0,l=2147483647;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>R>>C;
        u=min(R,u);
        d=max(R,d);
        l=min(C,l);
        r=max(C,r);
    }
    cout<<max((d-u+1)/2 , (r-l+1)/2)<<'\n';
    
}