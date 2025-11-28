#include <iostream>
using namespace std;

int main(){
    int x,y,z;
    cin>>x>>y>>z;

    for(int i=0; i<100000; i++){
        if(x == y*z){
            cout<<"Yes\n";
            return 0;
        }
        x++; y++;
    }

    cout<<"No\n";
}
