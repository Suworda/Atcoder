#include <iostream>
#include <string>
using namespace std;
int main() {
    long long n,ans1=0,ans2=0;
    string s;
    cin>>n>>s;
    int cur=1;
    for(int i=0; i<n*2; i++){
        if(s[i]=='B'){
            ans1+=abs(i-cur);
            cur+=2;
        }
    }
    cur=1;
    for(int i=0; i<n*2; i++){
        if(s[i]=='A'){
            ans2+=abs(i-cur);
            cur+=2;
        }
    }
    cout<<min(ans1,ans2)<<'\n';
    
    
}