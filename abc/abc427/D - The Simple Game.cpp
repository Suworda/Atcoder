#include <iostream>
#include <vector>
using namespace std;

void sol(){
    bool found=false;
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> edge[n+1];
    vector<char> a(n+1),b(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    int u,v;
    while(m--){
        cin>>u>>v;
        edge[u].push_back(v);
    }

    while(k--){
        for(int i=1; i<=n; i++){
            found=false; //found B
            for(auto &next:edge[i]){
                if(a[next]=='B'){
                    found=true;
                    break;
                }
            }

            if(found) b[i]='B';
            else b[i]='A';
        }

        for(int i=1; i<=n; i++){
            found=false; //found A
            for(auto &next:edge[i]){
                if(b[next]=='A'){
                    found=true;
                    break;
                }
            }

            if(found) a[i]='A';
            else a[i]='B';
        }
    }

    cout<<(a[1]=='A' ? "Alice" : "Bob") << '\n';


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) sol();
}
