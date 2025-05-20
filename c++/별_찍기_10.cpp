#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
    FASTIO

    int n; cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            int num = n;
            while(num /= 3){
                if((i/num)%3 == 1 && (j/num)%3 == 1) {cout << ' '; break;}
                if(num==1) {cout << '*'; break;}
            }    
        }
        cout << '\n';
    }


}