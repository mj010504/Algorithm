#include<bits/stdc++.h>

using namespace std;

// 간단한 문제일수록 조건을 세부적으로 잘 생각하기

int main() {
  //  freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int res = 0;

    for(int i = 0; i < n; i++) {
        int target = v[i];
        int left = 0, right = n - 1;
        while(left < right) {
            if(v[left] + v[right] == target) {
                if(left == i) left++;
                else if(right == i) right--;
               else {
                    res++;
                    break;
               }
            }
            else if(v[left] + v[right] < target) left++;
            else if(v[left] + v[right] > target) right--;
        }
    }
    
    cout << res;
}
