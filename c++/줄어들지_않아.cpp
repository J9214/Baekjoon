#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

long long sum(vector<long long> vec, int idx){
    long long s = 0;
    for(int i = 0 ; i <= idx; i++){
        s += vec[i];
    }

    return s;
}
int main() {
    FASTIO
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long> vec = {1,1,1,1,1,1,1,1,1,1};

        for(int i = 0; i < n; i++){
            for(int j = 9; j > 0; j--){
                vec[j] = sum(vec, j);
            }
        }

        cout << vec[9] << '\n';
    }

    
    
    
    return 0;
}