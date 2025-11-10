#include <iostream>
#include <cmath>
using namespace std;
int n;

long long f(int x){
    long long ans=0;
    for(int i=1; i*i<=x; i++){
        if(x%i==0){
            if(i*i==x) ans++;
            else ans+=2;
        }
    }
    return ans;
}

int main(){
    cin>>n;
    long long ans=0;

    //O(N * sqrt(N))
    for(int i=1; i<n; i++){
        ans+=f(i)*f(n-i);
    }

    //O(N * log N)
    ans=0;
    int cnt[200005]={};
    for(int a=1; a<=n; a++){
        for(int b=1; a*b<=n; b++){
            cnt[a*b]++;
        }
    }

    for(int i=1; i<n; i++){
        ans+=cnt[i]*cnt[n-i];
    }

    cout<<ans<<'\n';
}
