#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    long long x,y;
    cin>>x>>y;
    for(int i=0; i<9; i++){
        string s=to_string(x+y);
        reverse(s.begin(),s.end());
        long long a=stoll(s);
        x=a;
        swap(x,y);
    }
    cout<<x<<'\n';
}