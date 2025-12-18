#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    char c;
    int cur=0;
    while(cin>>c){
        s+=c;
        if(s.size()>=3 && s.substr(s.size()-3, 3) == "ABC"){
            for(int i=0; i<3; i++) s.pop_back();
        }

    }
    cout<<s<<'\n';

}