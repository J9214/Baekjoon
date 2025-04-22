#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	vector<double> vec(t);
	for(int i = 0 ; i < t; i++)
		cin >> vec[i];
	long long a,b,res=t;cin>>a>>b;
	for(double& v : vec){
		res+= min((long long)ceil((v-a)/b), (long long)ceil(v/b));
	}
	cout << res;
}
