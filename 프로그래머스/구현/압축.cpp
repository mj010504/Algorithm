#include<bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> res;
    map<string, int> m;
    int idx = 0;
    for(int i = 1; i <= 26; i++) {
        string temp = "";
        temp += 'A' + idx;
        m[temp] = i;
        idx++;
    }

    int vidx;
    while(vidx < msg.size()) {
        string temp = "";
        temp += msg[vidx];
        int print = m[temp];
        vidx ++;
        while(vidx < msg.size()) {
            temp += msg[vidx];
            if(m[temp] == 0) {
                m[temp] = ++idx; 
                break;
            }
            else {
                print = m[temp];
                vidx++;
            }
        }

        res.push_back(print);
    }

    return res;
}
