#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};
ll modulo = 1000000007;

vvll mat_mult(vvll vec1, vvll vec2){
    vvll vec(2, vector<ll>(2, 0));

    for(int i = 0 ; i < 2; i++){
        for(int j = 0 ; j < 2 ; j++){
            for(int k = 0 ; k < 2 ; k++){
                vec[i][j] += vec1[i][k] * vec2[k][j];
                if(vec[i][j] >= modulo) vec[i][j] %= modulo;
            }
        }
    }

    return vec;
}

vvll mat_square(vvll vec, long long b){
    int cnt = 0;
    vvll result(2, vector<ll>(2, 0));

    for(int i = 0 ; i < 2; i++){
        for(int j = 0 ; j < 2 ; j++){
            if(i == j) result[i][j] = 1;
        }
    }

    if(!b) return result;
    if(b % 2) return mat_mult(mat_square(vec, b - 1), vec);
    vvll half = mat_square(vec, b / 2);

    return mat_mult(half, half);
}

int main(){
    FASTIO
    
    long long n; cin >> n;
    if(!n){
        cout << 0 << '\n';
        return 0;
    } 
    

    vvll vec = {{1,1}, {1, 0}};
    vvll result1, result2;

    result1 = mat_square(vec, n + 1);
    result2 = mat_square(vec, n);

    ll value1 = result1[0][1] * result1[0][1] % modulo;
    ll value2 = result2[0][1] * result2[0][1] % modulo;

    cout << (value1 - value2 + (n % 2 ? 1 : -1) + modulo) %  modulo << '\n';
    

    return 0;
}