#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    vector<pair<int, int>> vec(6);
    int n; cin >> n;
    
    int x = 1000, y = 1000;
    for(int i = 0 ; i < 6 ; i++){
        int d, l; cin >> d >> l;
        if(d == 1) {
            x += l;
            vec.push_back({x,y});
        }
        if(d == 2){
            x -= l;
            vec.push_back({x,y});
        }
        if(d == 3){
            y -= l;
            vec.push_back({x,y});
        }
        if(d == 4){
            y += l;
            vec.push_back({x,y});
        }
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    
    
        cin >> vec[{x,y}];

    
    return 0;
}
