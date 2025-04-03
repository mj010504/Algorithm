#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "rt", stdin);  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n; cin >> c >> n;
    vector<pair<int, int>> pv;
   
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pv.push_back({a, b});
    }   

    vector<int> dp(1200, 21487900);
    dp[0] = 0;

    int maxx = c;
    for(int i = 0; i < n; i++) {
        int cost = pv[i].second;
        if(c % cost != 0) maxx = max(maxx, (c / cost) * cost +  cost);
    }

    for(int i = 0; i < n; i++) {
        for(int j = pv[i].second; j <= maxx; j++) {
            dp[j] = min(dp[j], dp[j - pv[i].second] + pv[i].first);
        } 
    }

    int res = INT_MAX;
    for(int i = c; i <= maxx; i++) {
        res = min(res, dp[i]);
    }

    cout << res;

    return 0;
}

/*
  배낭 문제와 유사한데 범위를 더 늘려줘야 한다는 것이 포인트
*/
