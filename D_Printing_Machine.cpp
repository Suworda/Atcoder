#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
pair<ll,ll> seg[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        ll t,d;
        cin>>t>>d;
        seg[i] = {t,t+d};
    }

    sort(seg, seg+n);

    ll now = 1;
    int ptr = 0;
    int ans=0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(ptr < n || pq.size()){
        
        while(pq.size() && pq.top() < now) pq.pop();
        
        if(ptr < n && pq.empty()){
            now = seg[ptr].first;
            pq.push(seg[ptr].second);
            ptr++;
        }
        
        while(ptr < n && seg[ptr].first == now){
            pq.push(seg[ptr].second);
            ptr++;
        }

        if(pq.size()){
            ans++;
            pq.pop(); 
            now++;      
        }
        
    }
    
    cout<<ans<<'\n';

}

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define ll long long

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     if (!(cin >> n)) return 0;

//     vector<pair<int, int>> items(n);
//     for (int i = 0; i < n; i++) {
//         // first: 進場時間 T, second: 持續時間 D
//         cin >> items[i].first >> items[i].second;
//     }

//     // 依照進場時間排序
//     sort(items.begin(), items.end());

//     // min-heap: 儲存「消失時間」(T + D)
//     priority_queue<int, vector<int>, greater<int>> pq;

//     int ans = 0;
//     int now = 0;
//     int i = 0;

//     while (i < n || !pq.empty()) {
//         // 如果當前沒有可以印的東西，時間跳躍到下一個物品進場
//         if (pq.empty()) {
//             now = items[i].first;
//         }

//         // 將所有在當前時間 (或之前) 進場的物品放入優先隊列
//         while (i < n && items[i].first <= now) {
//             pq.push(items[i].first + items[i].second);
//             i++;
//         }

//         // 清理掉已經過期、印不出來的物品
//         while (!pq.empty() && pq.top() < now) {
//             pq.pop();
//         }

//         // 如果還有可以印的，挑最快過期的印
//         if (!pq.empty()) {
//             pq.pop();
//             ans++;
//             now++; // 列印耗時 1 單位時間
//         }
//     }

//     cout << ans << "\n";

//     return 0;
// }