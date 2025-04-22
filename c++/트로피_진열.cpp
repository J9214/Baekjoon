#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, counting = 0;

    cin >> a;

    while(a > 0){
        counting++;
        a -= pow(floor(sqrt(a)), 2);
    }

    cout << counting;

    return 0;
}
