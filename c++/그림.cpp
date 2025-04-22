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
#define modulo 1000000007

int main(){
    FASTIO

    queue<pair<int,int>> q;
    vvi board(500, vi(500));

    int n, m; cin >> n >> m;

    for(int i =0 ; i < n ; i++)
        for(int j = 0 ; j < m; j++)
            cin >> board[i][j];
    
    int cnt = 0, res = 0;
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < m; j++){
            int area = 0;
            if(board[i][j]) {
                q.push({i, j});
                board[i][j] = 0;
                cnt++;
                area++;
            }
            while(!q.empty()){
                for(int k = 0 ; k < 4; k++){
                    int dx = q.front().first + direction[k].x;
                    int dy = q.front().second + direction[k].y;
                    if(0 <= dx && 0 <= dy && dx < n && dy < m && board[dx][dy]){
                        q.push({dx,dy});
                        board[dx][dy] = 0;
                        area++;
                    }
                }
                q.pop();
            }
            res = max(res, area);
        }
    }
    cout << cnt << '\n' << res;
        
}