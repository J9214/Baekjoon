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
typedef struct Point {double x, y, z;} point;
#define modulo 1000000007

int main(){
    FASTIO

    vector<point> vec;
    double cx=0,cy=0,cz=0,w=0.1;
    for(int i = 0; i < 3 ; i ++){
        double a, b, c; cin >> a >> b >> c;
        vec.push_back({a, b, c});
        cx+=a/3;
        cy+=b/3;
        cz+=c/3;
    }
    vector<double> dVec(3);
    for(int i = 0 ; i < 100000 ; i ++){
        for(int j = 0 ; j < 3 ; j++){
            dVec[j] = sqrt(pow(vec[j].x - cx, 2) + pow(vec[j].y - cy, 2)) + pow(vec[j].z - cz, 2);
        }
        
        double dx=0,dy=0,dz=0;
        for(int j = 0 ; j < 3 ; j++){
            dx += (cx - vec[j].x) / dVec[j];
            dy += (cy - vec[j].y) / dVec[j];
            dz += (cz - vec[j].z) / dVec[j];
        }

        cx = cx - dx * w;
        cy = cy - dy * w;
        cz = cz - dz * w;

        w *= 0.9999;
    }
    double res = 0;
    for(auto &i : vec){
        res += sqrt(pow(i.x-cx,2) + pow(i.y-cy,2) + pow(i.z-cz,2));
    }
    cout.precision(10);
    cout << res;
}