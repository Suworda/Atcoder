#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> A;
    int q;
    cin>>q;
    while(q--){
        int ty,x;
        cin>>ty;
        if(ty==1){
            cin>>x;
            A.push_back(x);
            sort(A.begin(), A.end(), greater<>());
        }else{
            if(!A.empty()){
                cout<<A[A.size()-1]<<'\n';
                A.pop_back();
            }
        }
    }
}