#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    string str;
    while(cin >> str){
        if(str == "#") break;
        int n = 0;
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '-') n += pow(8, str.size()- i - 1) * 0;
            else if(str[i] == '\\') n += pow(8, str.size()- i - 1) * 1;
            else if(str[i] == '(') n += pow(8, str.size()- i - 1) * 2;
            else if(str[i] == '@') n += pow(8, str.size()- i - 1) * 3;
            else if(str[i] == '?') n += pow(8, str.size()- i - 1) * 4;
            else if(str[i] == '>') n += pow(8, str.size()- i - 1) * 5;
            else if(str[i] == '&') n += pow(8, str.size()- i - 1) * 6;
            else if(str[i] == '%') n += pow(8, str.size()- i - 1) * 7;
            else if(str[i] == '/') n += pow(8, str.size()- i - 1) * -1;
        }
        cout << n << '\n';;
    }

    return 0;
}
