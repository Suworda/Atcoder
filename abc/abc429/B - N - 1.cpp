#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int tot=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        tot+=a[i];
    }

    for(int i=0; i<n; i++){
        if(tot-a[i]==m){
            cout<<"Yes\n";
            return 0;
        }
    }

    cout<<"No\n";
}
