#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};

vvi student; // 좋아하는 학생 수
vvi mat;
int s; // 학생 번호

int satisfy(){ // 만족도 계산
    int res = 0;
    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ; j < mat.size() ; j++){
            int adj_student_count = 0;
            for(int k = 0 ; k < 4; k++){
                int nx = i + direction[k].x;
                int ny = j + direction[k].y;
                if(nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat.size()) continue;
                if(student[mat[i][j]][mat[nx][ny]]) adj_student_count++; // 좋아하는 학생 수
            }
            int d = (adj_student_count > 0 ? pow(10, adj_student_count-1) : 0); // 개인 별 만족도 추가
            res += d; // 개인 별 만족도 추가
        }
    }
    return res;
}

void find(){ // 들어갈 수 있는 위치 찾기
    // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    // 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
    // 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
    vector<tuple<int, int, int, int>> idx; // (학생 번호, 행, 열)

    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ; j < mat.size() ; j++){
            if(mat[i][j] != 0) continue;

            int adj_student_count = 0;
            int adj_empty_count = 0;
            
            for(int k = 0 ; k < 4; k++){
                int nx = i + direction[k].x;
                int ny = j + direction[k].y;
                if(nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat.size()) continue;
                if(mat[nx][ny] == 0) adj_empty_count++; // 비어있는 칸
                if(student[s][mat[nx][ny]] == 1) adj_student_count++; // 좋아하는 학생
            }

            idx.push_back({-adj_student_count, -adj_empty_count, i, j}); // (좋아하는 학생 수, 비어있는 칸 수, 행, 열)
            // 큰 것부터 정렬하기 위해 - 붙임
        }
    }
    sort(idx.begin(), idx.end());
    auto [a,b,x,y] = idx[0];
    mat[x][y] = s; // 자리 배치
}
int main(){
    FASTIO

    int n; cin >> n;
    student.resize(n*n+1, vi(n*n+1, 0));
    mat.resize(n, vi(n, 0));
    
    for(int i = 0 ; i < n*n; i++){
        int l1, l2, l3, l4; // 좋아하는 학생 4명
        cin >> s >> l1 >> l2 >> l3 >> l4;
        
        student[s][l1] = student[s][l2] = student[s][l3] = student[s][l4] = 1; // 좋아하는 학생 수 표시
        find();
    }
    cout << satisfy(); // 만족도 계산
}