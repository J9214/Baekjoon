#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n, k;
    while(cin >> n >> k){
        int t = n;
        while(t >= k){
            n += t / k;
            t = t / k + t % k;
        }
        cout << n << '\n';
    }

    return 0;
}
