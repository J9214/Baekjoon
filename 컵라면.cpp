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

struct cmp {
	bool operator()(pi& a, pi& b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

int main(){
    FASTIO
    
    priority_queue<pi, vector<pi>, cmp> pq;
    int n; cin >> n;
    while(n--){
        int a, b; cin >> a >> b;
        pq.push({a,b});
    }
    int prev = 0, s=0, day = 1;
    priority_queue<int, vi, greater<int>> pq1;
    while(!pq.empty()){
        prev = pq.top().first;
        s += pq.top().second;
        pq1.push(pq.top().second);
        pq.pop();
        while(!pq.empty() && day >= pq.top().first){
            if(pq.top().second > pq1.top()){
                s += pq.top().second - pq1.top();
                pq1.pop();
                pq1.push(pq.top().second);
            }
            pq.pop();
        }

        day++;
    }
    cout << s;
}