#include <iostream>
using namespace std;

const int M=998244353;

int main(){
    long long n;
    cin>>n;
    cout<<(M+(n%M))%M<<'\n';
}
