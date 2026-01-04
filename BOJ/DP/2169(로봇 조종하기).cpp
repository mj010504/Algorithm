#include<bits/stdc++.h>

using namespace std;

int dx[3] = {0, 0, 1};
int dy[3] = {1, -1, 0};

struct p{
    int x, y, value;
};

int main() {
    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);

    int res = -INT_MAX;
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> v(1001, vector<int> (1001));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> v[i][j];
    }

    vector<vector<int>> dp(1001, vector<int> (1001, -21487900));
   vector<vector<int>> dp2(1001, vector<int> (1001, -21487900));
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp2[0][1] = 0;
    dp2[1][0] = 0;

    for(int i = 1; i <= m; i++) {
        dp[1][i] = dp[1][i - 1] + v[1][i];
        dp2[1][i] = dp[1][i - 1] + v[1][i];
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
        }

        for(int j = m; j >= 1; j--) {
            dp2[i][j] = max(dp2[i - 1][j], dp2[i][j + 1]) + v[i][j];
        }

        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j], dp2[i][j]);
            dp2[i][j] = dp[i][j];
        }
    }

    cout << dp[n][m];

    return 0;
}
