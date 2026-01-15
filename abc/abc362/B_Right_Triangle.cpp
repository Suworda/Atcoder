#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;


    int d[3];
    d[0] = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    d[1] = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
    d[2] = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
    
    sort(d,d+3);

    if(d[0] + d[1] == d[2]) cout<<"Yes\n";
    else cout<<"No\n";
}
