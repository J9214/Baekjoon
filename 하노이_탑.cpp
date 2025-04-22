#include <iostream>
#include <cmath>
using namespace std;

void hanoi_tower(int n, unsigned long long int a, int b, int c, unsigned long long int k){
    unsigned long long int l;

    l = pow(2, n - 1);
    
    
        cout << a << " " << c << '\n';
    
    
   if(k > l) return hanoi_tower(n - 1, b, a, c, k - l);
    else return hanoi_tower(n - 1, a, c, b, k);

}
int main(){
    unsigned long long int disks, tc, k;
    
    
        cin >> disks;

        hanoi_tower(disks, 1, 2, 3, disks);
    
    return 0;
}