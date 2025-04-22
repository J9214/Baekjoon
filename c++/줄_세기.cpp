#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
    string str;
    int c=0;
    while(getline(cin , str))
        c++;
    cout << c;
}