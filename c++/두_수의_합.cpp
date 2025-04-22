#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int i = 0 , j = vec.size() - 1;
    int m; cin >> m;
    int c = 0;
    while(i < j){
        if((vec[i] + vec[j]) == m) c++;
        if(vec[i] + vec[j] > m) j--;
        else i++;
    }
    
    cout << c;
    return 0;
}
