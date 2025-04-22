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

int main(){
    FASTIO

    int n,m,r;cin >> n >> m >> r;
    vvi vec(n+1);
    for(int i = 0 ; i < m;  i++){
        int a,b;cin >> a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i ++)
        sort(vec[i].rbegin(),vec[i].rend());
    
    vi visited(n+1,0);
    int num=1;
    queue<int> q;

    q.push(r);
    visited[r] = num++;
    while(!q.empty()){
        int from = q.front();
        q.pop();

        for(int i = 0 ; i < vec[from].size(); i++){
            int to = vec[from][i];
            if(visited[to]==0){
                q.push(to);
                visited[to] = num++;
            }
        }
                
    }
    for(int i =1; i <visited.size(); i++)
        cout << visited[i] << '\n';
}