#include <iostream>
using namespace std;

const int M=1000000007;

int main(){
    int n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    long long ans=0;

    //O(n^2)
//    for(int i=0; i<n-1; i++){
//        for(int j=i+1; j<n; j++){
//            cout<<i<<' '<<j<<':'<<(a[i]^a[j])<<'\n';
//            ans+=a[i]^a[j];
//            ans%=M;
//        }
//    }

    //O(n)
    for(int i=0; i<=60; i++){
        long long x = 0, y = 0;
        for(int j=0; j<n; j++){
//          x+=((a[j]&(1LL<<i))==(1LL<<i));
//          y+=((a[j]&(1LL<<i))!=(1LL<<i));
            x += ((a[j] >> i) & 1);
            y += !((a[j] >> i) & 1);
        }
        ans+=(x*y)%M * ((1LL<<i)%M);
        ans%=M;
        //cout<<x<<' '<<y<<'\n';
    }




    cout<<ans<<'\n';
}
