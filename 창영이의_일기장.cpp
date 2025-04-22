#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    string str; getline(cin, str);
    vector<char> res;

    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == 'a' || str[i] == 'u' || str[i] == 'o' || str[i] == 'i' ||str[i] == 'e')
            i += 2;
        cout << str[i];
    }
        
    return 0;
}