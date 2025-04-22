#include <bits/stdc++.h>
using namespace std;
int main(){
    string a, b, c; cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << '\n' << stoi(a+b) - stoi(c);
}