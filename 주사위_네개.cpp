#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

struct cmp{
    bool operator()(pi &a, pi &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

int main(){
    FASTIO
    int t; cin >> t;
    int res = 0;
    while(t--){
        map<int, int> m;
        for(int i= 0 ; i < 4; i++){
            int d; cin >> d;
            m[d]++;
        }
        priority_queue<pi, vpi, cmp> pq;
        for(auto it:m)
            pq.push({it.first, it.second});
        int ret;
        if(pq.top().second == 4) ret = 50000 + pq.top().first * 5000;
        else if(pq.top().second == 3) ret = 10000 + pq.top().first * 1000;
        else if(pq.top().second == 2){
            int top = pq.top().first;
            pq.pop();
            if(pq.top().second == 2){
                ret = 2000 + pq.top().first * 500 + top * 500; 
            } 
            else ret = 1000 + top * 100; 
        } 
        else ret = pq.top().first * 100; 
        
        res = max(res,ret);
    }
    cout << res;
}   