#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, c; cin >> n >> c;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int res = 1;
    int left = 1, right = v[n - 1] - v[0];
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = 1; // 시작점에 두고 공유기 설치
        int current = v[0];
        for(int i = 1; i < n; i++) {
            if(v[i] - current >= mid) {
                current = v[i];
                cnt++;

                if(cnt >= c) break;
            }
        }

        if(cnt >= c) {
            res = max(res, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << res;
}
