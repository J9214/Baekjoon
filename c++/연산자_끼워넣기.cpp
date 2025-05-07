#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int n, res_min=INT_MAX, res_max=INT_MIN; // 결과 값은 -10억 ~ 10억이므로 int 자료형 사용
vi vec, op(4); // op : + - * %
void dfs(int cnt, int ret){
    if(cnt == n){ // 수를 모두 연산에 사용하면 최대, 최소값 업데이트
        res_max = max(res_max, ret);
        res_min = min(res_min, ret);
        return;
    }
    for(int i = 0 ; i < 4; i++){
        if(op[i]){
            op[i]--;
            if(i==0) dfs(cnt+1, ret + vec[cnt]);
            else if(i==1) dfs(cnt+1, ret - vec[cnt]);
            else if(i==2) dfs(cnt+1, ret * vec[cnt]);
            else if(i==3) dfs(cnt+1, ret / vec[cnt]);
            op[i]++;
        }
    }
}
int main(){
    FASTIO

    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    for(int i = 0; i < 4; i++) cin >> op[i];

    dfs(1,vec[0]);

    cout << res_max << '\n' << res_min;
}