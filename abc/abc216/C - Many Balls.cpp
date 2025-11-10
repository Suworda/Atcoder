#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin>>n;
    string ans;
    while(n){
        if(n%2==1){
            ans+='A';
            n--;
        }else{
            ans+='B';
            n/=2;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<'\n';
}
