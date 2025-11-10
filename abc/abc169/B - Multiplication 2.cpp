#include <iostream>
using namespace std;

int main(){
    long long lim=1e18;
    int n;
    cin>>n;
    long long a[n+5];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==0){
            cout<<0<<'\n';
            return 0;
        }
    }

    long long cur=1;
    for(int i=0; i<n; i++){
        //cout<<cur<<' '<<lim/a[i]<<'\n';
        if(cur>lim/a[i]){
            cout<<-1<<'\n';
            return 0;
        }
        cur*=a[i];
    }

    cout<<cur<<'\n';
}
