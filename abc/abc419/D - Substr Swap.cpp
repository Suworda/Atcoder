#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;

bool d[500001];
string s,t;
int main(){
    cin>>n>>m>>s>>t;
    while(m--){
        int l,r;
        cin>>l>>r;
        l--; r;
        if(l==r)swap(s[l],t[r]);
        d[l]=!d[l];
        d[r]=!d[r];
    }
    bool change=false;
    for(int i=0; i<n; i++){
        if(d[i]) change=!change;
        if(change) swap(s[i],t[i]);
    }
    cout<<s<<'\n';
}