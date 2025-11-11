#include <iostream>
using namespace std;

string x;

void sol(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    for(int i=0; i<=10; i++){
        if(s==x.substr(i,k)){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";

}

signed main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    for(int i=1; i<=100; i++){
        if(i%3==0) x+='F';
        if(i%5==0) x+='B';
    }
    int t;
    cin>>t;
    while(t--) sol();

}
