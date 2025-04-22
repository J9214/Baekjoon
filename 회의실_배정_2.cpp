#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};

int main(){
    FASTIO
    
    int n ; cin >> n;
    vector<pair<pair<int, int>, int>> vec;
    int curr = 0, prev = 0, s = 0;
    while(n--){
        int a, b, d; cin >> a >> b >> d;
        vec.push_back({{a,b}, d});
    }

    sort(vec.begin(), vec.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
        return a.first.second < b.first.second;
    });

    for(int i = 0 ; i < vec.size(); i++){
        if(!prev) prev = vec[i].second;
        else if(!curr) curr = vec[i].second;
        
        if(curr && prev){
            s += max(curr, prev);
            curr = prev = 0;         
        }
    }
    
    cout << s;
    return 0;
}