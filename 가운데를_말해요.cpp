#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n ; cin >> n;
    priority_queue<int> main_pq;
    priority_queue<int, vector<int>, greater<int>> sub_pq;

    while(n--){
        int d; cin >> d;
        if(main_pq.empty()) main_pq.push(d);
        else if(d < main_pq.top()) {
            main_pq.push(d);

            if(main_pq.size() - sub_pq.size() > 1){
                sub_pq.push(main_pq.top());
                main_pq.pop();
            }
        }
        else {
            sub_pq.push(d);

            if(sub_pq.size() - main_pq.size() > 1){
                main_pq.push(sub_pq.top());
                sub_pq.pop();
            }
        }
        if(sub_pq.size() > main_pq.size()) cout << sub_pq.top() <<'\n';
        else cout << main_pq.top() << '\n';
    }
    
    return 0;
}