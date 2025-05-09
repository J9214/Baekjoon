#include <bits/stdc++.h>
using namespace std;

long long n, k, res=0;
vector<int> vec(k);
void func(long long t){
    if(t > n) return;
    res = max(res, t);
    for(int i = 0 ; i < k; i++)
        func(t*10+vec[i]);
}

int main() {
	cin >> n >> k;
    vec.resize(k);
    for(int i = 0 ; i < k; i++) cin >> vec[i];
    sort(vec.rbegin(), vec.rend());

    func(0);

    cout << res;
}
