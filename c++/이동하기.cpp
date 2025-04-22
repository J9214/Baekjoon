#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};
vvi vec, dp;

int find(point pos){
    int i, total = 0;
    point next;

    if(pos.x == vec.size() - 1 && pos.y == vec[pos.x].size() -1) return vec[vec.size() - 1][vec[pos.x].size() - 1];
    priority_queue<int> pq;

    for(i = 0 ; i < 3; i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if( next.x >= 0 && next.x <= vec.size() - 1 &&
            next.y >= 0 && next.y <= vec[pos.x].size() - 1)
        {
            pq.push(find(next));
        }
    }

    return total + pq.top();
}
int main(){
    FASTIO
    int n, m; cin >> n >> m;
    vec.assign(n, vi(m));
    dp.assign(n, vi(m, -1));

    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < m; j++){
            int d; cin >> d;
            vec[i][j] = d;
        }
    }
    
    cout << find({0, 0});
    return 0;
}