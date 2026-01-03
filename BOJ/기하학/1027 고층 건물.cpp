#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++) {
        double maxx = INT_MIN;
        for(int j = i + 1; j < n; j++) {
            double temp = (double)(v[j] - v[i]) / (j - i);
            if(temp > maxx) {
                cnt[i]++; cnt[j]++;
                maxx = temp;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, cnt[i]);
    }

    cout << res;
}
