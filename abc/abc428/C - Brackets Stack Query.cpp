#include <iostream>
using namespace std;
int sum_l[800005]={}, sum_r[800005]={};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    int ty;
    char c;
    int l=0,r=0;
    bool ans=true;
    string s;
    int wrong=0;
    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>c;
            s+=c;
            if(c == '('){
                l++;

            }else{ // ')'
                r++;

            }

            int sz=s.size();
            sum_l[sz]=sum_l[sz-1]+(c == '(');
            sum_r[sz]=sum_r[sz-1]+(c == ')');
            wrong+=(sum_l[sz]<sum_r[sz]);

        }else{
            c=s[s.size()-1];
            if(c == '('){
                l--;

            }else{ // ')'
                r--;

            }

            int sz=s.size();
            wrong-=(sum_l[sz]<sum_r[sz]);
            sum_l[sz]=0;
            sum_r[sz]=0;

            s.pop_back();

        }



        cout<<(!wrong && l==r ? "Yes\n" : "No\n");
    }
}
