#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vec;
    map<int, int> mp;

    while(n--){
        int w, v; cin >> w >> v;
        vec.push_back({w, v});
    }
    sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    });

    while(m--){
        int c; cin >> c;
        mp[c]++;
    }

    long long s = 0;

    for(int i = 0 ; i < vec.size(); i++){
        auto it = mp.lower_bound(vec[i].first);
        
        if(it==mp.end()) 
            continue;
        else {
            s += vec[i].second;
            it->second--;
            if(it->second==0){
                mp.erase(it);
            }  
        }
    }
    cout << s;
    
    return 0;
}