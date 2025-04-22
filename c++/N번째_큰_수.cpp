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

    priority_queue<int, vector<int>, greater<int>> pq;
    int n; cin >> n;
    int t = n * n;
    while(t--){
        int d; cin >> d;
        if(pq.size() <= n || d > pq.top()) pq.push(d);
        if(pq.size() > n) pq.pop();
    }
    cout << pq.top();
}