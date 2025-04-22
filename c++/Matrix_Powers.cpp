#include<bits/stdc++.h>
using namespace std;

int modulo;

vector<vector<int>> mat_mult(vector<vector<int>> vec1, vector<vector<int>> vec2, long long n){
    vector<vector<int>> vec(n, vector<int>(n, 0));

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

vector<vector<int>> mat_square(vector<vector<int>> vec, long long n, long long b){
    int cnt = 0;
    vector<vector<int>> result(n, vector<int>(n, 0));

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) result[i][j] = 1;
        }
    }

    if(!b) return result;
    if(b % 2) return mat_mult(mat_square(vec, n, b - 1), vec, n);
    vector<vector<int>> half = mat_square(vec, n, b / 2);

    return mat_mult(half, half, n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, b, data;
    
    while(1){
        cin >> n >> modulo >> b;
        if(!(n || modulo || b)) break;
        vector<vector<int>> vec(n, vector<int>(n, 0));
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                cin >> data;
                vec[i][j] = data;
            }
        }

        vector<vector<int>> result;

        result = mat_square(vec, n, b);

        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                cout << result[i][j]  % modulo << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    

    return 0;
}