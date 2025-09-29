#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s[n+1];
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    int x;
    string y;
    cin>>x>>y;
    if(s[x]==y) cout<<"Yes\n";
    else cout<<"No\n";
}