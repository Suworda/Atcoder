#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int max_sz=0;
        int cur=0;
        int ans1=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                ans1+=2;
                cur++;
            }else{
                ans1++;
                cur=0;
            }
            max_sz=max(max_sz,cur);
        }
        ans1-=max_sz*2;

        max_sz=0;
        cur=0;
        int ans2=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                ans2+=2;
                cur++;
            }else{
                ans2++;
                cur=0;
            }
            max_sz=max(max_sz,cur);
        }
        ans2-=max_sz*2;

        cout<<min(ans1,ans2)<<'\n';
    }

}
