#include <iostream>
using namespace std;

signed main(){
    int cnt[128]={};
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        cnt[s[i]]++;
    }

    for(int i=0; i<128; i++){
        if(cnt[i]==1){
            cout<<char(i)<<'\n';;
        }
    }
}
