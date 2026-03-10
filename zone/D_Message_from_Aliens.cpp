#include <bits/stdc++.h>
using namespace std;

char dq[1000005];
int front=500001, back=500000;
bool rev;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char c;
    while(cin>>c){
        // cout<<front<<' '<<back<<' ';
        // if(!rev){
        //     for(int i=front; i<=back; i++) cout<<dq[i];
        // }else{
        //     for(int i=back; i>=front; i--) cout<<dq[i];
        // }
        // cout<<'\n';

        if(c == 'R'){
            rev = !rev;
            continue;
        }

        if(!rev){
            if(front <= back && c == dq[back]) back--;
            else dq[++back] = c;

        }else{
            if(front <= back && c == dq[front]) front++;
            else dq[--front] = c;
        }


    }

    if(!rev){
        for(int i=front; i<=back; i++) cout<<dq[i];
    }else{
        for(int i=back; i>=front; i--) cout<<dq[i];
    }
    
    
    
    
    
}
