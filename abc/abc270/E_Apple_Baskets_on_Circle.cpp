#include <bits/stdc++.h>
using namespace std;

#define int long long

long long n,k;
long long a[100005];

bool valid(long long x){
    long long gain=0;
    for(int i=0; i<n; i++){
        gain += min(x , a[i]);
    }
    return gain <= k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    long long rst=0;
    long long l=1, r=1e14;
    while(l<=r){
        long long mid = (l+r)/2;

        if(valid(mid)){
            rst = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    //cout<<rst<<'\n';

    for(int i=0; i<n; i++){
        long long ori=a[i];
        a[i] = max(0LL, a[i]-rst);
        k -= ori - a[i];
    }

    for(int i=0; i<n && k ; i++){
        if(a[i]){
            a[i]--;
            k--;
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';



}