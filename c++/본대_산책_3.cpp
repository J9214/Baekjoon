#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};
ll modulo = 1000000007;

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

    vvll mat = {
        {1,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,1}
    };

    if(!b) return mat;
    if(b % 2) return mat_mult(mat_square(vec, n, b - 1), vec, n);
    vvll half = mat_square(vec, n, b / 2);

    return mat_mult(half, half, n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, d; cin >> n >> d;

    vvll mat(n, vll(n, 0));

    for(int i =0  ; i< d; i++){
        int a, b; cin >> a >> b;
        mat[a][b] = mat[b][a] = 1;  
    }

    ll p; cin >> p;
    vvll result = mat_square(mat, mat.size(), p);

    ll s= 0;
    for(int i =0  ; i < n ; i++)
        s += (mat[0][i] + modulo) % modulo;
    cout << s;
    return 0;
}