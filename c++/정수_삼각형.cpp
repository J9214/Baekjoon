#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(){
    FASTIO

    int n; cin >> n;
    int res = 0; // 최댓값 경로
    vvi mat(n+1, vi(n+1, 0)); 

    for(int i = 1 ; i <= n ; i++) // 
        for(int j = 1 ; j <= i ; j++){
            cin >> mat[i][j]; // 값 입력

            if(j==1) mat[i][j] += mat[i-1][j]; // 왼쪽 대각선
            else if(j==i) mat[i][j] += mat[i-1][j-1]; // 오른쪽 대각선
            else mat[i][j] += max(mat[i-1][j], mat[i-1][j-1]);

            res = max(res, mat[i][j]); // 최댓값 업데이트
        }
    cout << res;
}