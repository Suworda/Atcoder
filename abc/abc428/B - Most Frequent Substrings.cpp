#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int> cnt;
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    n=s.size();
    for(int i=0; i<=n-k; i++){
        cnt[s.substr(i,k)]++;
    }

    int most=0;
    for(auto &x: cnt){
        most=max(most, x.second);
    }

    cout<<most<<'\n';
    for(auto &x: cnt){
        if(x.second==most) cout<<x.first<<' ';
    }
    cout<<'\n';
}
