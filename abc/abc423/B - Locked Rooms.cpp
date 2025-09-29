#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    int l=0,r=0;
    for(int i=0; i<n; i++){
        if(a[i]==1){
            l=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(a[i]==1){
            r=i;
            break;
        }
    }
    cout<<r-l<<'\n';
    
}