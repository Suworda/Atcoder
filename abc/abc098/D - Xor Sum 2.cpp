#include<iostream>
using namespace std;
const int SIZE = 200'000;
int nxt[SIZE+5][20];
int a[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<20; i++) nxt[n][i] = nxt[n+1][i] = n;

    for(int p=n-1; p>=0; p--){
        for(int i=0; i<20; i++){
            nxt[p][i]=nxt[p+1][i];

            if((a[p]>>i) & 1 == 1) nxt[p][i]=p;
        }
    }

    long long ans=0;
    for(int l=0; l<n; l++){
        int r=n-1;
        for(int i=0; i<20; i++){
            r=min(r, nxt[nxt[l][i] + 1][i] -1);
        }
        ans+=r-l+1;
    }

    cout<<ans<<'\n';
}
