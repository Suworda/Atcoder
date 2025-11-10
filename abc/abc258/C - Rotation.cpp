#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    string s;
    cin>>n>>q>>s;

    int d=0;
    while(q--){
        int ty,x;
        cin>>ty>>x;

        if(ty==1){
            d+=x;
            d%=n;

        }else{
            x--;
            x-=d;
            x=(x+n)%n;
            cout<<s[x]<<'\n';
        }
    }

}
