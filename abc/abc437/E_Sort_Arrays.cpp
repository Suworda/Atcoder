#include <bits/stdc++.h>
using namespace std;

struct Node{
    vector<int> id;
    map<int, Node*> child;
    
};


void dfs(Node *node){
    for(int x: node->id){
        cout<<x<<' ';
    }
    
    for(auto &x: node->child){
        dfs(x.second);
    }
    //cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //node[0] = new Node;
    
    int n;
    cin>>n;
    vector<Node*> node(n+5);

    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        if(!node[x]) node[x] = new Node;
        if(!node[x]->child.count(y)) node[x]->child[y] = new Node;
        node[i] = node[x]->child[y];
        node[x]->child[y]->id.push_back(i);

        //cout<<node[y]->id[0]<<'\n';
    }

    dfs(node[0]);

}