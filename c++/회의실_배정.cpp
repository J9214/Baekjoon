#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    vector<pair<int,int>> vec;
    int n,k ; cin >> n >> k;
    while(n--){
        int a, b; cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin(),  vec.end(), [](pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    });

    int cnt = 0, s = 0;

    map<int, int, greater<int>> m;

    for(int i = 0 ; i < vec.size(); i++){
        auto it = m.upper_bound(vec[i].first);
        auto its = m.upper_bound(vec[i].second);
        
        if(it==m.end()) 
            if(cnt == k) continue;
            else {
                m[vec[i].second]++;
                cnt++;
                s++;
                continue;
            }

            it->second--;
            cnt--;
            if(it->second==0){
                m.erase(it);
            }      
        
        m[vec[i].second]++;
        s++;
        cnt++;
    }

    cout  <<  s;

    
    return 0;
}