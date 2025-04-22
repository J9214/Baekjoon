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

double calcVec(pair<double, double> a, pair<double, double> b){
    return sqrt(b.first -)
}
double matching(vector<pair<bool, pair<double, double>>> vec){
    int res = 987654321;
    for(int i = 0 ; i < vec.size(); i++){
        if(vec[i].first) continue;
        for(int j = i + 1; j < vec.size(); j++){
            if(vec[j].first) continue;
            
        }
    }
}

int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<bool, pair<double, double>>> vec;
        for(int i = 0 ; i < n ; i++){
            int a, b; cin >> a >> b;
            vec[i] = {0,{a,b}};
        }

        
    }
}