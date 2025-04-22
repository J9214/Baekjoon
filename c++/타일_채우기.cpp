#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n; cin >> n;
    vector<long long> vec;
    vec.push_back(3);
    vec.push_back(11);

    for(int i = 2 ; i < n/2; i++)
        vec.push_back((vec[i-1] * 4 - vec[i-2]) % 1000000007);
    
    if(n % 2) cout << 0;
    else cout << vec[n/2 - 1];

    return 0;
}