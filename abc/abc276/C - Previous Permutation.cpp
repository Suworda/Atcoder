#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int p[n];
    for(int i=0; i<n; i++){
        cin>>p[i];
    }

    for(int i=n-2; i>=0; i--){
        if(p[i]>p[i+1]){
            for(int j=i+1; j<=n; j++){
                if(j==n || p[i] < p[j]){
                    swap(p[i],p[j-1]);
                    break;
                }
            }
            sort(p+i+1, p+n, greater());
            break;
        }
    }

    //¤º«Ø¨ç¦¡
//    prev_permutation(p,p+n);c
//
    for(int i=0; i<n; i++){
        cout<<p[i]<<' ';
    }
    cout<<'\n';


}
