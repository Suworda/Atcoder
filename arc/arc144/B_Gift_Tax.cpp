#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n,a,b;
int A[MAXN];

bool valid(int x){
    long long rst=0;
    for(int i=0; i<n; i++){
        if(A[i] < x){
            rst += (x - A[i])/a;
            if((x - A[i])%a != 0) rst++;

        }else if(A[i] > x){
            rst -= (A[i] - x)/b;
        }
    }
    return rst <= 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>a>>b;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    int ans;
    int l=1, r=1e9;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            l = mid +1;
        }else{
            r = mid -1;
        }
    }

    cout<<ans<<'\n';
}