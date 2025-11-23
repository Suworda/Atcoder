#include <bits/stdc++.h>
using namespace std;

//string f(int x){
//    if(x==1) return "1";
//    return f(x-1) + " " + to_string(x) + " " + f(x-1);
//}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>n;

    auto f = [](auto && self , int x) ->string {
        if(x==1) return "1";
        return self(self , x-1) + " " + to_string(x) + " " + self(self , x-1);
    };

    cout << f(f,n) << '\n';
}
