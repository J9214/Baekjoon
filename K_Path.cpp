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
#define modulo 1000000007

vvll mat_mult(vvll vec1, vvll vec2, ll n){
    vvll vec(n, vll(n, 0));

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                vec[i][j] += vec1[i][k] * vec2[k][j];
                if(vec[i][j] >= modulo) vec[i][j] %= modulo;
            }
        }
    }

    return vec;
}

vvll mat_square(vvll vec, ll n, ll b){
    vvll result(n, vll(n, 0));

    vvll mat(n, vll(n));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if(i == j) mat[i][j] = 1;

    if(!b) return mat;
    if(b % 2) return mat_mult(mat_square(vec, n, b - 1), vec, n);
    vvll half = mat_square(vec, n, b / 2);

    return mat_mult(half, half, n);
}

int main(){
    FASTIO

    int n, k ; cin >> n >> k;
    vvll mat(n, vll(n));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> mat[i][j];

    vvll result = mat_square(mat, n, k);

    ll s = 0;
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            s = (s + result[i][j] + modulo) % modulo;

    cout << s;
    
}   