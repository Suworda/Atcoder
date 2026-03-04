#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> tails;

    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        auto it = tails.lower_bound(x);
        if(it == tails.begin()){
            tails.insert(x);
        }else{
            it--;
            tails.erase(it);
            tails.insert(x);
        }
    }

    cout<<tails.size()<<'\n';
}