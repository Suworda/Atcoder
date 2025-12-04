#include <bits/stdc++.h>
using namespace std;

long long f(long long a, long long b){
    return a*a*a + a*a*b + a*b*b + b*b*b; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin>>n;
    long long ans = 9e18;

    //cout<<f(0,0)<<'\n';

    for(int a=0, b=1000000; a<=1000000; a++){
        while(b > 0 && f(a,b-1) >= n) b--;
        //cout<<a<<' '<<b<<':'<<f(a,b)<<'\n';
        ans = min(ans,f(a,b));
    }

    cout<<ans<<'\n';

}