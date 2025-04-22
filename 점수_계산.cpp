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
    priority_queue<pi> pq;
    for(int i = 1; i <= 8; i++){
        int d; cin >> d;
        pq.push({d,i});
    }
    vi vec;
    int n=0;
    for(int i = 1; i <= 5; i++){
        vec.push_back(pq.top().second);
        n+=pq.top().first;
        pq.pop();
    }
    sort(vec.begin(),vec.end());
    cout << n << '\n';
    for(int i = 0; i < 5; i++){
        cout << vec[i] << ' ';
    }
}