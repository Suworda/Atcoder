#include <iostream>
#include <cmath>
using namespace std;

#define int long long

long long cnt(int l, int r){
    int a,b;
    l--;
    a=(int)sqrt(r);
    b=(int)sqrt(l);

    a+=2; b+=2;
    while(a*a>r){
        a--;
    }
    while(b*b>l){
        b--;
    }

    return a-b;
}

signed main(){
    int t;
    cin>>t;
    int c,d;
    while(t--){
        long long ans=0;
        cin>>c>>d;
        int x=1,l,r;
        while(x<=c+d){
            l=max(c+1,x); r=min(x*10-1,c+d);
            if(l>r){
                x*=10;
                continue;
            }

            ans+=cnt(c*x*10+l , c*x*10+r);


            x*=10;
        }
        cout<<ans<<'\n';
    }
}
