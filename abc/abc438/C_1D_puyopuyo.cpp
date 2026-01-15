#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        if(v.size() >= 4){
            bool rm = true;
            for(int j=v.size()-3; j<v.size(); j++){
                if(v[j] != v[j-1]) rm = false;
                //cout<<j<<' ';
            }
            //cout<<' '<<rm<<' ';

            if(rm){
                for(int j=0; j<4; j++){
                    v.pop_back();
                }
            }
        }

        // for(int x: v) cout<<x<<' ';
        // cout<<'\n';

    }

    cout<<v.size();

}