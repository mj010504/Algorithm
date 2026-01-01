#include<bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(string dirs) {
    int res = 0;
    int v[11][11][4] = {0};
    int x = 5, y = 5;

    for(auto d : dirs) {
        int temp;
        if(d == 'U') {
            temp = 3;
        }
        else if(d == 'D') {
            temp = 2;
        }
        else if(d == 'L') {
            temp = 1;
        }
        else {
            temp = 0;
        }

        int xx = x + dx[temp];
        int yy = y + dy[temp];
        if(xx >= 0 && xx <= 10 && yy >= 0 && yy <= 10) {
            if(temp == 0 && v[xx][yy][0] == 0) {
                v[x][y][1] = 1;
                v[xx][yy][0] = 1;
                res++;
            }
            else if(temp == 1 && v[xx][yy][1] == 0) {
                v[x][y][0] = 1;
                v[xx][yy][1] = 1;
                res++;
            }
            else if(temp == 2 && v[xx][yy][2] == 0) {
                v[x][y][3] = 1;
                v[xx][yy][2] = 1;
                res++;
            }
            else if(temp == 3 && v[xx][yy][3] == 0){
                v[x][y][2] = 1;
                v[xx][yy][3] = 1;
                res++;
            }

            x = xx, y = yy;
        }
    }

    return res;
}
