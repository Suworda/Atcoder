#include <bits/stdc++.h>
using namespace std;

int n,k;
long long x;
int a[300005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k>>x;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<>());

    bool found = false;
    for(int i=0; i<n; i++){
        if(k == n) x-=a[i];
        else k++;

        if(x <= 0){
            cout<<i+1<<'\n';
            found = 1;
            break;
        }
    }
    
    if(!found) cout<<-1<<'\n';
}
