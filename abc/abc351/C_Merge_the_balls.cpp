#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    stack<int,vector<int>> stk;
    while(n--){
        int x;
        cin>>x;
        while(stk.size() && x == stk.top()){
            stk.pop();
            x++;
        }
        stk.push(x);
    }

    cout<<stk.size()<<'\n';

}