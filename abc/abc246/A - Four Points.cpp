#include <iostream>
using namespace std;

int main(){
    int x,y;
    int ans_x=0, ans_y=0;
    for(int i=0; i<3; i++){
        cin>>x>>y;
        ans_x^=x;
        ans_y^=y;
    }
    cout<<ans_x<<' '<<ans_y<<'\n';
}
