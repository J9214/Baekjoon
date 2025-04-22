#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n; cin >> n;
    vector<long long> vec(n);
    for(int i = 0 ; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    
    
    long long mat_i = 0, mat_j = 1, mat_k = vec.size() - 1;

    for(long long i = 0 ; i < vec.size() - 2; i++){
        long long j = i + 1,  k = vec.size() - 1;    

        while(j < k){
            long long prev = abs(vec[mat_i] + vec[mat_j] + vec[mat_k]);
            long long curr = vec[i] + vec[k] + vec[j];

            if(abs(curr) < prev){
                mat_i = i;
                mat_k = k;
                mat_j = j;
            }

            if(curr < 0) j++;
            else k--;
        }
    }
    cout << vec[mat_i] << ' ' << vec[mat_j] << ' ' << vec[mat_k];
        
    return 0;
}