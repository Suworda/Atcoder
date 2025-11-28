#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    s+='x';
    vector<pair<char,int>> v;

    int cnt=1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            cnt++;
        }else{
            v.push_back({s[i-1] , cnt});
            cnt=1;
        }
    }

    long long ans=0;

    for(int i=1; i<v.size(); i++){
        if(v[i].first == v[i-1].first +1){
            ans+=min(v[i].second, v[i-1].second);
        }
    }

    cout<<ans<<'\n';
}
