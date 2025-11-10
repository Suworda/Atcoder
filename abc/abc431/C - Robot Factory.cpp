#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int h[n];
    int b[m];

    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<m; i++) cin>>b[i];
    sort(h,h+n);
    sort(b,b+m);

//    for(int i=0; i<n; i++) cout<<h[i]<<' ';
//    cout<<'\n';
//    for(int i=0; i<m; i++) cout<<b[i]<<' ';
//    cout<<'\n';

    int r=0;
    int cnt=0;
    for(int l=0; l<n; l++){
        while(h[l]>b[r] && r<m) r++;
        if(r==m) break;
        cnt++;
        r++;
    }

    //cout<<cnt<<'\n';

    cout<<(cnt>=k ? "Yes" : "No")<<'\n';

}
