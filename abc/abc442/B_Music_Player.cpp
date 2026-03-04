#include <bits/stdc++.h>
using namespace std;

bool stop=1;
int v;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a == 1){
            v++;
        }else if(a == 2){
            v = max(0, v-1);
        }else{
            stop ^=1;
        }

        if(!stop && v>=3) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
