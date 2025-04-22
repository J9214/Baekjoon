#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};

const int Type[23][4][2] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, 
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {0, -1}, {-1, -1}, {-2, -1}},
    {{0, 0}, {-1, 0}, {-1, 1}, {-1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, 
    {{0, 0}, {1, 0}, {1, -1}, {1, -2}},
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}}, 
    {{0, 0}, {-1, 0}, {-1, -1}, {-1, -2}}, 
    {{0, 0}, {0, -1}, {1, -1}, {2, -1}}, 
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {-1, 0}, {1, 0}, {0, -1}}, 
    {{0, 0}, {-1, 0}, {1, 0}, {0, 1}}, 
    {{0, 0}, {0, -1}, {0, 1}, {-1, 0}}, 
    {{0, 0}, {0, -1}, {0, 1}, {1, 0}}, 
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, 
    {{0, 0}, {0, -1}, {1, -1}, {1, -2}}, 
    {{0, 0}, {-1, 0}, {-1, -1}, {-2, -1}}, 
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}}, 
    {{0, 0}, {0, -1}, {-1, -1}, {-1, -2}}, 
    {{0, 0}, {-1, 0}, {-1, 1}, {-2, 1}}, 
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}

};


int cover(vvi board){
    int res = 0;

    for(int i = 0 ; i< board.size() ; i++){
        for(int j = 0; j < board[i].size() ; j++){
            for(int k = 0; k < 23; k++){
                int tmp = 0;
                bool ok = true;
                for(int l = 0; l < 4; l++){
                    int nx = i + Type[k][l][0];
                    int ny = j + Type[k][l][1];
                    if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[i].size()) {
                        ok = false;
                        break;
                    }
                    else tmp += board[nx][ny];
                }
                if(ok) res = max(tmp, res);
            }

        }
    }
    return res;
}

int main(){
    FASTIO
    
    int n, m; cin >> n >> m;
    vvi board(n, vi(m));

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> board[i][j];
    
    cout << cover(board);
    
    return 0;
}