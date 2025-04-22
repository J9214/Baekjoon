#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        n--;
        int res = 0;
        set<int> s;

        for(int i = 1; i < n / 2; i++){
            if(n % i == 0) {
                s.insert(i);
                s.insert(n / i);
            }
        }
        cout << s.size();   
    }
    return 0;   
}
