#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    pair<int,int> a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a,a+n);

    for(int i=0; i<3; i++){
        cout<<a[i].second<<' ';
    }
    cout<<'\n';
}
