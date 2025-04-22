#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n; cin >> n;
    vector<int> vec(n);
    for(int i =0 ;  i < n ; i++)
        cin >> vec[i];
    
    sort(vec.rbegin(), vec.rend());

    for(int i =0 ;  i < n ; i++)
        cout << vec[i] << '\n';
    
    
    return 0;
}