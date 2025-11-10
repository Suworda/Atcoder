#include <iostream>
using namespace std;

const long long M=998244353;

int main(){
    long long a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    a%=M; b%=M; c%=M; d%=M; e%=M; f%=M;
    cout<<((a*b%M*c - d*e%M*f)%M + M)%M<<'\n';
}
