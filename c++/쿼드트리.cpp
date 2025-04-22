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

bool chk(vector<vector<char>> vec, int x, int y, int d){
    for(int i=  x; i < x + d ; i++){
        for(int j =y ;  j < y + d; j++){
            if(vec[i][j] != vec[x][y]) return 0;
        }
    }    
    return 1;
}

void quad(vector<vector<char>> vec, int x, int y, int d){
    if(d == 1 || chk(vec, x, y, d)) cout << vec[x][y];
    else {
        cout << "(";
        d >>= 1;
        quad(vec, x, y, d);
        quad(vec, x, y + d, d);
        quad(vec, x + d, y, d);
        quad(vec, x + d, y + d, d);
        cout << ")";
    }
}

int main(){
    FASTIO
    
    int n; cin >> n;
    vector<vector<char>> vec(n, vector<char>(n));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j ++)
            cin >> vec[i][j];
    
    quad(vec, 0,0,n);
}