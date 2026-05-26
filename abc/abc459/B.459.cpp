#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

map<char,int> c;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    c['a'] = 2;
    c['b'] = 2;
    c['c'] = 2;
    c['d'] = 3;
    c['e'] = 3;
    c['f'] = 3;
    c['g'] = 4;
    c['h'] = 4;
    c['i'] = 4;
    c['j'] = 5;
    c['k'] = 5;
    c['l'] = 5;
    c['m'] = 6;
    c['n'] = 6;
    c['o'] = 6;
    c['p'] = 7;
    c['q'] = 7;
    c['r'] = 7;
    c['s'] = 7;
    c['t'] = 8;
    c['u'] = 8;
    c['v'] = 8;
    c['w'] = 9;
    c['x'] = 9;
    c['y'] = 9;
    c['z'] = 9;
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        cout<<c[s[0]];
    }
}
