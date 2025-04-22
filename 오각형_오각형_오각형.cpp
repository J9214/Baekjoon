#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    long long n ; cin >> n;
    long long s = (n * (n + 1)) / 2;
    cout << (3 * s + n + 1) % 45678;
    
    return 0;
}