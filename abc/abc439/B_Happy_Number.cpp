#include <bits/stdc++.h>
using namespace std;

bool checked[100000];

int f(int n){
    int rst = 0;
    string s = to_string(n);
    for(int i=0; i<s.size(); i++){
        rst += (s[i]-'0')*(s[i]-'0');
    }
    // cout<<rst<<'\n';
    return rst;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    while(!checked[n]){
        checked[n] = 1;
        n = f(n);
    }

    cout<<(n == 1 ? "Yes\n" : "No\n");
}