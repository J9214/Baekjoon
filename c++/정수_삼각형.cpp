#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n; cin >> n;
    vector<vector<int>> vec(n);
    
    for(int i =0 ; i < n; i++){
        for(int j = 0 ; j <= i ; j++){
            int d; cin >> d;
            vec[i].push_back(d);
        }
    }
    
    int m = vec[0][0];

    for(int i =1 ; i < n; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0) vec[i][j] += vec[i-1][j];
            else if(j == i) vec[i][j] += vec[i-1][j-1];
            else vec[i][j] += max(vec[i-1][j],vec[i-1][j-1]);
            m = max(m, vec[i][j]);
        }
    }
    cout << m;
    return 0;
}
