#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
vvi vec, dp;

int find(point pos){
    int i, total = 0;
    point next;

    if(pos.x == vec.size() - 1 && pos.y == vec[pos.x].size() -1) return 1;
    if(dp[pos.x][pos.y] != -1) return dp[pos.x][pos.y];

    for(i = 0 ; i < 4; i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if( next.x >= 0 && next.x <= vec.size() - 1 &&
            next.y >= 0 && next.y <= vec[pos.x].size() - 1 &&
            vec[next.x][next.y] < vec[pos.x][pos.y])
        {
            total += find(next);
        }
    }

    dp[pos.x][pos.y] = total;
    return total;
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