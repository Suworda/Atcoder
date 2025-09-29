#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int score[n]={};
    int maxs=0;
    bool b[n];
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    
    for(int i=0; i<m; i++){
        int zero=0;
        int one=0;
        for(int j=0; j<n; j++){
            b[j]=(s[j][i]=='1');
            if(s[j][i]=='0') zero++;
            else one++;
        }
        
        for(int j=0; j<n; j++){
            if(one>zero) score[j]+=(s[j][i]=='0');
            else score[j]+=(s[j][i]=='1');
        }
        
    }
    for(int i=0; i<n; i++){
        maxs=max(score[i],maxs);
    }
    
    for(int i=0; i<n; i++){
        if(score[i]==maxs) cout<<i+1<<' ';
    }
    cout<<'\n';
    
}