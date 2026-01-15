#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x3 = x2 - dy;
    int y3 = y2 + dx;

    cout<<x3<<' '<<y3<<' '<<x1 - dy<<' '<<y1 + dx<<'\n';
    
}
