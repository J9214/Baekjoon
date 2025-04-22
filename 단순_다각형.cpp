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
#define modulo 1000000007

struct Point{
    ll x, y;
    bool operator < (const Point &a){
        return y == a.y ? x < a.x : y < a.y;
    }
};
vector<pair<int, Point>> vec;
ll ccw(const Point &a, const Point &b, const Point &c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
ll dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool cmp(const pair<int, Point> &a, const pair<int, Point> &b){
    ll c = ccw(vec[0].second, a.second, b.second);
    if(c == 0) return dist(vec[0].second, a.second) < dist(vec[0].second, b.second);
    return c > 0;
}

int main(){
    FASTIO

    int tc; cin >> tc;
    while(tc--){
        vec.clear();
        ll n ; cin >> n;
        for(int i = 0 ; i < n ; i++){
            int a, b; cin >> a >> b;
            vec.push_back({i,{a,b}});
        }

        sort(vec.begin(), vec.end(), [](pair<int, Point> &a, pair<int, Point> &b){
            if(a.second.y == b.second.y) return a.second.x < b.second.x;
            return a.second.y < b.second.y;
        });
        sort(vec.begin() + 1, vec.end(), cmp);

        vector<pair<int, Point>> A;
        vector<pair<int, Point>> R;
        for(int i = 0; i < vec.size(); i++){
            if(A.size() >= 2 && ccw(A[A.size() - 2].second, A.back().second, vec[i].second)<0){
                R.push_back(A.back());
                A.pop_back();
            }
            A.push_back(vec[i]);
        }
        for(ll i = R.size() - 1; i >= 0; i--)  
            A.push_back(R[i]);

        for(int i = 0; i <A.size(); i++){
            cout << A[i].first << ' ';
        }
        cout << '\n';
    }
    
}