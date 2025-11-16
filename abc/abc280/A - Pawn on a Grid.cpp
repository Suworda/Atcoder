#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h,w;
    cin>>h>>w;
    string s;
    char c;
    for(int i=0; i<h*w; i++){
        cin>>c;
        s+=c;
    }

    cout<< count(s.begin(), s.end(), '#') <<'\n';

}

