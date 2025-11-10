#include <iostream>
using namespace std;

const int M=998244353;

int main(){
    long long n;
    cin>>n;
    long long x=1;
    while(x <= n){
        x*=10;
    }

    long long ans=0;
    long long a,b;

    for(long long i=1; i<x; i*=10){
        if(i*10>n){
            a = n - i + 1;
            b = a + 1;
        }else{
            a = i*10 - i;
            b = a + 1;
        }

        if(a%2 == 0) a/=2;
        else b/=2;
        ans+=(a%M)*(b%M)%M;
        ans%=M;
    }

    cout<<ans<<'\n';
}
