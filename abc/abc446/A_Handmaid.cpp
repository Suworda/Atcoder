#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    string s;
    cin>>s;

    cout<<"Of"<<char(s[0]+32);
    for(int i=1; i<s.size(); i++) cout<<s[i];
}
