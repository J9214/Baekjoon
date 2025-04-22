#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, counting = 0, mc = 0;
 
    cin >> a;
    double b = floor(sqrt(a));
    for(int i = b ; i > 0; i--){
        counting = 0;
        while(a > 0){
            counting++;
            a -= pow(floor(sqrt(i)), 2);
        }
        mc = min(mc, counting);
    }

    cout << counting;

    return 0;
}
