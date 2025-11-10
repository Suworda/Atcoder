#include <iostream>
using namespace std;

const int M=998244353;

int main(){
    long long n;
    cin>>n;
    long long a=n%M, b=n;
    long long x=1;
    for(int i=0; i<to_string(n).size(); i++){
        x*=10;
        x%=M;
    }

    long long ans=0;

    while(b){
        if(b & 1) ans = (ans*x + a);
        a = a*x + a;
        x*=x;
        a%=M; x%=M; ans%=M;
        b>>=1;
    }

    cout<<ans<<'\n';
}
