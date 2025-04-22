#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};

int modulo = 10000;

vvi mat_mult(vvi vec1, vvi vec2){
    vvi vec(2, vector<int>(2, 0));

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

vvi mat_square(vvi vec, long long b){
    int cnt = 0;
    vvi result(2, vector<int>(2, 0));

    for(int i = 0 ; i < 2; i++){
        for(int j = 0 ; j < 2 ; j++){
            if(i == j) result[i][j] = 1;
        }
    }

    if(!b) return result;
    if(b % 2) return mat_mult(mat_square(vec, b - 1), vec);
    vvi half = mat_square(vec, b / 2);

    return mat_mult(half, half);
}

int main(){
    FASTIO
    
    while(1){
        long long n; cin >> n;
        if(n == -1) break;
        if(n == 0) {
            cout << 0 << '\n';
            continue;
        }

        vvi vec = {{1,1}, {1, 0}};
        vvi result;

        result = mat_square(vec, n);

        cout << result[0][1] << '\n';
    }

    return 0;
}