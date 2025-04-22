#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n, data;

    cin >> n;
    
    vector<int> vec;

    while(n-->0){
        cin >> data;
        vec.push_back(data);
    }

    sort(vec.begin(), vec.end());

    int matching_left = 0;
    int matching_right = vec.size() - 1;
    int left = 0;
    int right = vec.size() - 1;

    while(left < right){
        int prev = abs(vec[matching_left] + vec[matching_right]);
        int curr = vec[left] + vec[right];

        if(abs(curr) < prev){
            matching_left = left;
            matching_right = right;
        }

        if(curr < 0) left++;
        else right--;
    }

    cout << vec[matching_left] << ' ' << vec[matching_right];
    
    return 0;
}