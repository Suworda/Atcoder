#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n,m;
int L[MAXN];

bool valid(long long w){
    long long y=w;
    int cnt=1;

    for(int i=0; i<n; i++){
        if(L[i] > w) return false;

        if(y - L[i] < 0){
            cnt++;
            y = w;
        }
        y -= L[i];
        y--;
    }

    return cnt <= m;

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>L[i];
    }

    long long ans;
    long long l=1, r=4e18;
    while(l <= r){
        long long mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid -1;
        }else{
            l = mid +1;
        }
    }

    cout<<ans<<'\n';

}