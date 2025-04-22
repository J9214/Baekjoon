#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    int n, m;
    __int128_t nCm = 1;

    cin >> n >> m;

    for(int i = 1; i <= min(n,n-m); i++){
        nCm *= n - i + 1;
        nCm /= i;
    }

    string s;
    while(nCm){
        s.push_back("0123456789"[nCm%10]);
        nCm/=10;
    }
    for(int i = s.size()-1; i>=0; i--)
        cout << s[i];
    
    return 0;
}
    