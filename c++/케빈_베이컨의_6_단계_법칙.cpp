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
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO

    int n, m; cin >> n >> m;

    vvi vec(n+1, vi(n+1, 0));
    vvi graph(n+1);

    while(m--) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;

    int res = INT_MAX, num;
    for(int i = 1; i <= n ; i++){
        int t_res=0;
        q.push(i);
        while(q.size()){
            int curr = q.front(); q.pop();

            for(auto j : graph[curr])
                if(j != i && !vec[i][j]) {
                    vec[i][j] = vec[i][curr] + 1;
                    t_res += vec[i][j];
                    q.push(j);
                }
        }
        if(res > t_res){
            res = t_res;
            num = i;
        }
    }    
    cout << num;
}