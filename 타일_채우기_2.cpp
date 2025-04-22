#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

vector<long long> res(vector<long long> vec, vector<vector<long long>> mat){
    vector<long long> res_vec(2);
    res_vec[0] = (vec[0] * mat[0][0] + vec[1] * mat[1][0]) % MOD;
    res_vec[1] = (vec[0] * mat[0][1] + vec[1] * mat[1][1]) % MOD;
    
    return res_vec;
}

vector<vector<long long>> matmul(vector<vector<long long>> &dim, vector<vector<long long>> &dim2){
    vector<vector<long long>> res(2,vector<long long>(2,0));
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j ++){
            for(int k = 0 ; k < 2; k++){
                res[i][j] += dim[i][k] * dim2[k][j];
                res[i][j] = res[i][j] % MOD + MOD;
            }
        }
    }
        
    return res;
}

int main() {
    FASTIO
    
    long long n; cin >> n;

    if(n % 2){
            cout << 0 << '\n';
        } else{

            n /= 2;     

            int position = 0, mask = 1;

            vector<vector<long long>> total = {{1, 0}, {0, 1}};

            while(n > 0){
                if(n & mask == 1){
                    vector<vector<long long>> dim = {{4, 1}, {-1, 0}};
                    
                    for(int j = 0 ; j < position; j++)
                        dim = matmul(dim, dim);
                    
                    total = matmul(total, dim);
                }
                position++;
                n >>= 1;
            } 

            vector<long long> result_vec = {3,1};
            result_vec = res(result_vec, total);
            
            cout << result_vec[1];
        }

    return 0;
}