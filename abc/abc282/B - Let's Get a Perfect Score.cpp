#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int can_sol[n]={};
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            if(s[j]=='o') can_sol[i] |= (1<<j);
        }
    }

    int ans=0;
    int need=(1<<m)-1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans+=((can_sol[i] | can_sol[j]) == need);
        }
    }

    cout<<ans<<'\n';
}
