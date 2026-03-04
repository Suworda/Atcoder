#include <bits/stdc++.h>
using namespace std;

string s,t;
int cntS[300005];
int cntT[300005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s>>t;
    string x,y;
    int id=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] != 'A'){
            x.push_back(s[i]);
            id++;

        }else{
            cntS[id]++;

        }
    }

    id=0;
    for(int i=0; i<t.size(); i++){
        if(t[i] != 'A'){
            y.push_back(t[i]);
            id++;

        }else{
            cntT[id]++;

        }
    }

    if(x != y){
        cout<<-1<<'\n';
        return 0;
    }   

    int ans=0;
    for(int i=0; i<=x.size(); i++){
        ans += abs(cntS[i] - cntT[i]);
    }

    cout<<ans<<'\n';


    

}
