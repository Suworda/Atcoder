#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int d,f;
    cin>>d>>f;

    while(f<=d){
        f+=7;
    }

    //if(f%d == 0) cout<<f<<'\n';
    cout<<f%d<<'\n';


}