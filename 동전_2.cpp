#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n, m; cin >> n >> m;
    vector<int> coins(n);

        for(int i = 0 ; i < n ; i++)   
            cin >> coins[i];
        

        vector<long long> goal(m + 1, 1000000000);
        goal[0] = 0;

        for(int i = 0 ; i < n; i++){
            for(int j = coins[i] ; j <= m; j++){
                if(j == coins[i]) goal[j] = 1;
                else if(goal[j - coins[i] < 1000000000]){
                    goal[j] = min(goal[j], goal[j - coins[i]] + 1);
                    
                } 
            }
        }
        
        if(goal[m] < 1000000000) cout << goal[m];
        else cout << -1;

    return 0;
}