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
    __int128 x, y;
    bool operator < (const Point &a){
        return y != a.y ? x < a.x : y < a.y;
    }
};

__int128 ccw(const Point &a, const Point &b, const Point &c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int main(){
    FASTIO
    vector<Point> vec(4);
    for(int i =0 ; i <4;i++){
        ll a, b; cin >> a >> b;
        vec[i] = {a,b};
    }
    __int128 ab,cd;
    ab = ccw(vec[0],vec[1],vec[2]) * ccw(vec[0],vec[1],vec[3]);
    cd = ccw(vec[2],vec[3],vec[0]) * ccw(vec[2],vec[3],vec[1]); 
    
    if(ab < 0 && cd < 0)
        cout << 1;
    else cout << 0;

}