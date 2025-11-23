#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int h,w,n;
    cin>>h>>w>>n;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        cin>>b[i];
    }

    vector<int> c=a ,d=b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    c.resize(unique(c.begin(),c.end()) - c.begin());
    d.resize(unique(d.begin(),d.end()) - d.begin());

    for(int i=0; i<n; i++){
        auto it = lower_bound(c.begin(), c.end(), a[i]);
        cout << (it - c.begin() +1) <<' ';

        it = lower_bound(d.begin(), d.end(), b[i]);
        cout << (it - d.begin() +1) <<'\n';
    }
}
