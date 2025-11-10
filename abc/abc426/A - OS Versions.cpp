#include <iostream>
#include <map>
using namespace std;

signed main(){
    map<string,int> v;
    v["Ocelot"]=1;
    v["Serval"]=2;
    v["Lynx"]=3;
    string x,y;
    cin>>x>>y;
    if(v[x]>=v[y]){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
