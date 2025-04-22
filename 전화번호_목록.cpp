#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> vec(n);
        for(int i = 0 ; i < n ; i++)
            cin >> vec[i];
        
        sort(vec.begin(), vec.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        int s = 0;

        for(int i =0 ; i < n - 1 ; i++){
            if(vec[i].size() == 10) break;
            for(int j = i + 1 ; j < vec.size() ; j++){
                if(vec[i] == vec[j].substr(0, vec[i].size())) s++;
                if(s) break;
            }
            if(s) break;
        }
        if(s) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }
    
    return 0;
}