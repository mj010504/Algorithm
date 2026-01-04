#include<bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 탈출불가능하다는 조건을 놓쳐서 시간초과에서 헤메었다.

int main() {
   // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    pair<int, int> p;
    vector<pair<int, int>> fv;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'J') {
                p = {i, j};
                v[i][j] = '.';
            }
            if(v[i][j] == 'F') {
                fv.push_back({i, j});
            }
        }
    }

    int res = -1;
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(p);
    v[p.first][p.second] = '*';
    while(res == -1) {
        vector<pair<int, int>> tfv;
        for(auto f : fv) {
            int x = f.first, y = f.second;
            for(int d = 0; d < 4; d++) {
                int xx = x + dx[d];
                int yy = y + dy[d];

                if(xx >= 0 && xx < n && yy >= 0 && yy <= m && (v[xx][yy] == '.' || v[xx][yy] == '*')) {
                    v[xx][yy] = 'F';
                    tfv.push_back({xx, yy});
                }
            }
        }
        fv = tfv;

        queue<pair<int, int>> tq;
        bool temp = false;
        while(!q.empty()) {
            if(res != -1) break;
            auto tp = q.front(); q.pop();
            int px = tp.first, py = tp.second;
            for(int d = 0; d < 4; d++) {
                int xx = px + dx[d];
                int yy = py + dy[d];
                if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    if(v[xx][yy] == '.') {
                        temp = true;
                        tq.push({xx, yy});
                        v[xx][yy] = '*';
                    }
                }
                else {
                    res = cnt;
                    break;
                }
            }
        }
       
        if(res != -1 || temp == false) break;
        q = tq;
        cnt++;
    }


    if(res == -1) cout << "IMPOSSIBLE";
    else cout << res;

    return 0;
}
