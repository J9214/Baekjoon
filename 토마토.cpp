#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef struct Point {int x, y, z;} point;
point direction[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<queue<point>> QQ;
queue<point> q;

int main(){

    FASTIO
    int n, m, h, data, v = 0, res, days = 0, cnt = 0;

    cin >> m >> n >> h;

    vector<vector<vector<int>>> vec(n, vector<vector<int>>(m, vector<int>(h)));

    for(int i = 0 ; i < h; i++){
        for(int j = 0; j< n ;j++){
            for(int k = 0 ; k < m; k++){
                cin >> data;
                vec[j][k][i] = data;
                if(data == -1) v++;
                if(data == 1) {
                    q.push({j,k,i});
                    cnt++;
                }
            }
        }
    }

    QQ.push(q);
    res = n * m * h - v;

    while(!QQ.empty()){
        q = QQ.front();
        while(!QQ.front().empty()) QQ.front().pop();
        
        while(!q.empty()){
            point current = q.front();
            q.pop();
            
            for(int k = 0 ; k < 6; k++){
                int dx = current.x + direction[k].x;
                int dy = current.y + direction[k].y;
                int dz = current.z + direction[k].z;
            
                if(dx < 0 || dy < 0 || dz < 0 || dx >= n || dy >= m || dz >= h) continue;
                if(vec[dx][dy][dz] == 1 || vec[dx][dy][dz] == -1) continue;

                QQ.front().push({dx,dy,dz});
                vec[dx][dy][dz] = 1;
                cnt++;   
            }
        }
        if(QQ.front().empty()) break;

        days++;
    }
    
    if(cnt == res) cout << days;
    else cout << -1;
}
