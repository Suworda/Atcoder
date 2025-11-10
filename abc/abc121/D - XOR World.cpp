//#include <iostream>
//using namespace std;
//
//int main(){
//    long long a,b;
//    cin>>a>>b;
//    long long cur=0;
//    for(long long i=a; i<=b; i++){
//        cur^=i;
//        cout<<cur<<'\n';
//    }
//
//    cout<<cur<<'\n';
//}

#include <iostream>
using namespace std;

int main(){
    long long a,b;
    cin>>a>>b; b++;
    long long ans=0;
    bool val[60]={};
    val[0]=(b/2-a/2) & 1;

    long long x,y;
    for(int i=1; i<=60; i++){
        y=max(0LL , b%(1LL << i+1) - (1LL << i));
        x=max(0LL , a%(1LL << i+1) - (1LL << i));

        val[i]=(y-x) & 1;

    }

    for(int i=0; i<=60; i++){
        ans+=val[i]*(1LL << i);
    }

    cout<<ans<<'\n';
}
