#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    vector<int> sosu;
    vector<bool> vec(1005000,0);
    sosu.push_back(2);

    for(int i = 4; i < vec.size(); i+= 2)
        vec[i] = 1;

    for(int i = 3; i < vec.size(); i += 2){
        if(vec[i] == 1) continue;
        int j = i + i;
        sosu.push_back(i);

        while(j < vec.size()){
            vec[j] = 1;
            j += i;
        }
    }

    int t; cin >> t;

    while(t--){
        int n ; cin >> n;
        int s = 0;

        for(int i = 0;  i < sosu.size(); i++){
            if(sosu[i] > n / 2) break;
            if(!vec[n - sosu[i]]) s++;
        }
        
        cout << s << '\n';
    }
    return 0;   
}
